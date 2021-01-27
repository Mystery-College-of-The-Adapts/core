// Copyright (c) 2020-2021, NVIDIA CORPORATION. All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//  * Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//  * Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//  * Neither the name of NVIDIA CORPORATION nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
// PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#pragma once

#include <stddef.h>
#include <stdint.h>
#include "triton/core/tritonserver.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _COMPILING_TRITONREPOAGENT
#if defined(_MSC_VER)
#define TRITONREPOAGENT_DECLSPEC __declspec(dllexport)
#define TRITONREPOAGENT_ISPEC __declspec(dllimport)
#elif defined(__GNUC__)
#define TRITONREPOAGENT_DECLSPEC __attribute__((__visibility__("default")))
#define TRITONREPOAGENT_ISPEC
#else
#define TRITONREPOAGENT_DECLSPEC
#define TRITONREPOAGENT_ISPEC
#endif
#else
#if defined(_MSC_VER)
#define TRITONREPOAGENT_DECLSPEC __declspec(dllimport)
#define TRITONREPOAGENT_ISPEC __declspec(dllexport)
#else
#define TRITONREPOAGENT_DECLSPEC
#define TRITONREPOAGENT_ISPEC
#endif
#endif

struct TRITONREPOAGENT_Agent;
struct TRITONREPOAGENT_AgentModel;

///
/// TRITONREPOAGENT API Version
///
/// The TRITONREPOAGENT API is versioned with major and minor version
/// numbers. Any change to the API that does not impact backwards
/// compatibility (for example, adding a non-required function)
/// increases the minor version number. Any change that breaks
/// backwards compatibility (for example, deleting or changing the
/// behavior of a function) increases the major version number. A
/// repository agent should check that the API version used to compile
/// the agent is compatible with the API version of the Triton server
/// that it is running in. This is typically done by code similar to
/// the following which makes sure that the major versions are equal
/// and that the minor version of Triton is >= the minor version used
/// to build the agent.
///
///   uint32_t api_version_major, api_version_minor;
///   TRITONREPOAGENT_ApiVersion(&api_version_major, &api_version_minor);
///   if ((api_version_major != TRITONREPOAGENT_API_VERSION_MAJOR) ||
///       (api_version_minor < TRITONREPOAGENT_API_VERSION_MINOR)) {
///     return TRITONSERVER_ErrorNew(
///       TRITONSERVER_ERROR_UNSUPPORTED,
///       "triton repository agent API version does not support this agent");
///   }
///
#define TRITONREPOAGENT_API_VERSION_MAJOR 0
#define TRITONREPOAGENT_API_VERSION_MINOR 1

/// Get the TRITONREPOAGENT API version supported by Triton. This
/// value can be compared against the
/// TRITONREPOAGENT_API_VERSION_MAJOR and
/// TRITONREPOAGENT_API_VERSION_MINOR used to build the agent to
/// ensure that Triton is compatible with the agent.
///
/// \param major Returns the TRITONREPOAGENT API major version supported
/// by Triton.
/// \param minor Returns the TRITONREPOAGENT API minor version supported
/// by Triton.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_DECLSPEC TRITONSERVER_Error* TRITONREPOAGENT_ApiVersion(
    uint32_t* major, uint32_t* minor);

/// TRITONREPOAGENT_ArtifactType
///
/// The ways that the files that make up a model's repository content
/// are communicated between Triton and the agent.
///
///   TRITONREPOAGENT_ARTIFACT_FILESYSTEM: The model artifacts are
///     communicated to and from the repository agent via a locally
///     accessible filesystem. The agent can access these files using
///     an appropriate filesystem API.
///
typedef enum TRITONREPOAGENT_artifacttype_enum {
  TRITONREPOAGENT_ARTIFACT_FILESYSTEM
} TRITONREPOAGENT_ArtifactType;

/// TRITONREPOAGENT_ActionType
///
/// Types of repository actions that can be handled by an agent.
///
///   TRITONREPOAGENT_ACTION_LOAD: A not-currently-loaded model is
///     being loaded.
///
///   TRITONREPOAGENT_ACTION_RELOAD: A currently loaded model is
///     being reloaded.
///
typedef enum TRITONREPOAGENT_actiontype_enum {
  TRITONREPOAGENT_ACTION_LOAD,
  TRITONREPOAGENT_ACTION_RELOAD
} TRITONREPOAGENT_ActionType;

/// Get the location of the files that make up the model. The
/// 'location' communicated depends on how the model is being
/// communicated to the agent as indicated by 'artifact_type'.
///
///   TRITONREPOAGENT_ARTIFACT_FILESYSTEM: The model artifacts are
///     made available to the agent via the local
///     filesytem. 'location' returns the full path to the directory
///     in the model repository that contains the model's
///     artifacts. The returned location string is owned by Triton,
///     not the caller, and so should not be modified or freed. The
///     contents of the directory are owned by Triton, not the agent,
///     and so the agent should not delete or modify the contents. Use
///     TRITONREPOAGENT_RepositoryAcquire and
///     TRITONREPOAGENT_RepositoryCommit to get a location that can be
///     used to modify the model repository contents.
///
/// \param agent The agent.
/// \param model The model.
/// \param artifact_type Returns the artifact type for the location.
/// \param path Returns the location.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_DECLSPEC TRITONSERVER_Error*
TRITONREPOAGENT_ModelRepositoryLocation(
    TRITONREPOAGENT_Agent* agent, TRITONREPOAGENT_AgentModel* model,
    TRITONREPOAGENT_ArtifactType* artifact_type, const char** location);

/// Acquire a location where the agent can produce a new version of
/// the model repository files. The agent takes ownership of the
/// location until it is released by calling
/// TRITONREPOAGENT_ModelRepositoryLocationCommit or
/// TRITONREPOAGENT_ModelRepositoryLocationDelete. Initially the
/// acquired location is empty. The 'location' communicated depends on
/// how the model is being communicated to the agent as indicated by
/// 'artifact_type'.
///
///   TRITONREPOAGENT_ARTIFACT_FILESYSTEM: The location is a directory
///     on the local filesystem. 'location' returns the full path to
///     an empty directory that the agent should populate with the
///     model's artifacts. The returned location string is owned by
///     Triton, not the agent, and so should not be modified or freed.
///
/// \param agent The agent.
/// \param model The model.
/// \param artifact_type Returns the artifact type for the location.
/// \param path Returns the location.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_DECLSPEC TRITONSERVER_Error*
TRITONREPOAGENT_ModelRepositoryLocationAcquire(
    TRITONREPOAGENT_Agent* agent, TRITONREPOAGENT_AgentModel* model,
    TRITONREPOAGENT_ArtifactType* artifact_type, const char** location);

/// Commit a previously acquired location as the new model repository
/// for a model. The agent releases ownership of the location with
/// this call and so must not access or modify the location or its
/// contents after this call. The agent must not call
/// TRITONREPOAGENT_ModelRepositoryLocationDelete after this call.
///
/// \param agent The agent.
/// \param model The model.
/// \param path The location to commit.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_DECLSPEC TRITONSERVER_Error*
TRITONREPOAGENT_ModelRepositoryLocationCommit(
    TRITONREPOAGENT_Agent* agent, TRITONREPOAGENT_AgentModel* model,
    const char* location);

/// Discard and release ownership of a previously acquired location
/// and its contents. The agent must not access or modify the location
/// or its contents after this call.
///
/// \param agent The agent.
/// \param model The model.
/// \param path The location to release.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_DECLSPEC TRITONSERVER_Error*
TRITONREPOAGENT_ModelRepositoryLocationDelete(
    TRITONREPOAGENT_Agent* agent, TRITONREPOAGENT_AgentModel* model,
    const char* location);

/// Get the number of agent parameters defined for a model.
///
/// \param agent The agent.
/// \param model The model.
/// \param count Returns the number of input tensors.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_DECLSPEC TRITONSERVER_Error*
TRITONREPOAGENT_ModelParameterCount(
    TRITONREPOAGENT_Agent* agent, TRITONREPOAGENT_AgentModel* model,
    uint32_t* count);

/// Get a parameter name and value. The caller does not own the
/// returned strings and must not modify or delete them.
///
/// \param agent The agent.
/// \param model The model.
/// \param index The index of the parameter. Must be 0 <= index <
/// count, where count is the value returned by
/// TRITONREPOAGENT_ModelParameterCount.
/// \param parameter_name Returns the name of the parameter.
/// \param parameter_value Returns the value of the parameter.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_DECLSPEC TRITONSERVER_Error* TRITONREPOAGENT_ModelParameter(
    TRITONREPOAGENT_Agent* agent, TRITONREPOAGENT_AgentModel* model,
    const uint32_t index, const char** parameter_name,
    const char** parameter_value);

/// Get the model configuration. The caller takes ownership of the
/// message object and must call TRITONSERVER_MessageDelete to release
/// the object. If the model repository does not contain a
/// config.pbtxt file then 'model_config' is returned as nullptr.
///
/// \param agent The agent.
/// \param model The model.
/// \param config_version The model configuration will be returned in
/// a format matching this version. If the configuration cannot be
/// represented in the requested version's format then an error will
/// be returned. Currently only version 1 is supported.
/// \param model_config Returns the model configuration as a message.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_DECLSPEC TRITONSERVER_Error* TRITONREPOAGENT_ModelConfig(
    TRITONREPOAGENT_Agent* agent, TRITONREPOAGENT_AgentModel* model,
    const uint32_t config_version, TRITONSERVER_Message** model_config);

///
/// The following functions can be implemented by an agent. Functions
/// indicated as required must be implemented or the agent will fail
/// to load.
///

/// Initialize an agent. This function is optional. This function is
/// called once when an agent is loaded to allow the agent to
/// initialize any state associated with the agent. An agent has a
/// single state that is shared across all invocations of the agent.
///
/// \param agent The agent.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_ISPEC TRITONSERVER_Error* TRITONREPOAGENT_Initialize(
    TRITONREPOAGENT_Agent* agent);

/// Finalize for an agent. This function is optional. This function is
/// called once, just before the agent is unloaded. All state
/// associated with the agent should be freed and any threads created
/// for the agent should be exited/joined before returning from this
/// function.
///
/// \param agent The agent.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_ISPEC TRITONSERVER_Error* TRITONREPOAGENT_Finalize(
    TRITONREPOAGENT_Agent* agent);

/// Handle an action for a specified model. This function is
/// required. Triton will not perform multiple simultaneous calls to
/// this function for a given agent and model; however, there may be
/// simultaneous calls for the agent for different models.
///
/// If the agent does not handle the action the agent should
/// immediately return success (nullptr).
///
/// To modify the model's repository the agent must use
/// TRITONREPOAGENT_ModelRepositoryLocationAcquire and
/// TRITONREPOAGENT_ModelRepositoryLocationCommit and then return
/// success (nullptr). If the agent does not need to make any changes
/// to the model repository it should not call
/// TRITONREPOAGENT_ModelRepositoryLocationCommit and then return
/// success.
///
/// \param agent The agent.
/// \param model The model that is the target of the action.
/// \action_type The type of action the agent should handle for the model.
/// \return a TRITONSERVER_Error indicating success or failure.
TRITONREPOAGENT_ISPEC TRITONSERVER_Error* TRITONREPOAGENT_ModelAction(
    TRITONREPOAGENT_Agent* agent, TRITONREPOAGENT_AgentModel* model,
    const TRITONREPOAGENT_ActionType action_type);

#ifdef __cplusplus
}
#endif