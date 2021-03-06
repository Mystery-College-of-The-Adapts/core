// Copyright (c) 2020, NVIDIA CORPORATION. All rights reserved.
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
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES{} LOSS OF USE, DATA, OR
// PROFITS{} OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
// OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#if defined(_MSC_VER)
#define TRITONBACKEND_DECLSPEC __declspec(dllexport)
#elif defined(__GNUC__)
#define TRITONBACKEND_DECLSPEC __attribute__((__visibility__("default")))
#else
#define TRITONBACKEND_DECLSPEC
#endif

extern "C" {
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ApiVersion()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_DataTypeString()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_StringToDataType()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_DataTypeByteSize()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_MemoryTypeString()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ParameterTypeString()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InstanceGroupKindString()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_LogIsEnabled()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_LogMessage()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ErrorNew()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ErrorDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ErrorCode()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ErrorCodeString()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ErrorMessage()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ResponseAllocatorNew()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ResponseAllocatorDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_MessageNewFromSerializedJson()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_MessageDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_MessageSerializeToJson()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_MetricsDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_MetricsFormatted()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceTraceLevelString()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceTraceActivityString()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceTraceNew()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceTraceDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceTraceId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceTraceParentId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceTraceModelName()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceTraceModelVersion()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestNew()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestSetId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestFlags()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestSetFlags()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestCorrelationId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestSetCorrelationId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestPriority()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestSetPriority()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestTimeoutMicroseconds()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestSetTimeoutMicroseconds()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestAddInput()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestRemoveInput()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestRemoveAllInputs()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestAppendInputData()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestRemoveAllInputData()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestAddRequestedOutput()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestRemoveRequestedOutput()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestRemoveAllRequestedOutputs()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestSetReleaseCallback()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceRequestSetResponseCallback()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceResponseDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceResponseError()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceResponseModel()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceResponseId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceResponseParameterCount()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceResponseParameter()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceResponseOutputCount()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceResponseOutput()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_InferenceResponseOutputClassificationLabel()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsNew()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetServerId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetModelRepositoryPath()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetModelControlMode()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetStartupModel()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetStrictModelConfig()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetPinnedMemoryPoolByteSize()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetCudaMemoryPoolByteSize()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetMinSupportedComputeCapability()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetExitOnError()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetStrictReadiness()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetExitTimeout()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetLogInfo()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetLogWarn()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetLogError()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetLogVerbose()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetMetrics()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetGpuMetrics()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetBackendDirectory()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerOptionsSetBackendConfig()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerNew()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerStop()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerPollModelRepository()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerIsLive()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerIsReady()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerModelIsReady()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerModelBatchProperties()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerModelTransactionProperties()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerMetadata()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerModelMetadata()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerModelStatistics()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerModelConfig()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerModelIndex()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerLoadModel()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerUnloadModel()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerMetrics()
{
}
TRITONBACKEND_DECLSPEC void
TRITONSERVER_ServerInferAsync()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ApiVersion()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_MemoryManagerAllocate()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_MemoryManagerFree()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_InputProperties()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_InputBuffer()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_OutputBuffer()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_RequestId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_RequestCorrelationId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_RequestInputCount()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_RequestInputName()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_RequestInput()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_RequestInputByIndex()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_RequestOutputCount()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_RequestOutputName()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_RequestRelease()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseFactoryNew()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseFactoryDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseFactorySendFlags()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseNew()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseNewFromFactory()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseDelete()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseSetStringParameter()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseSetIntParameter()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseSetBoolParameter()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseOutput()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ResponseSend()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_BackendName()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_BackendConfig()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_BackendExecutionPolicy()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_BackendSetExecutionPolicy()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_BackendArtifacts()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_BackendMemoryManager()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_BackendState()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_BackendSetState()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelName()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelVersion()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelRepository()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelConfig()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelAutoCompleteConfig()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelSetConfig()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelServer()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelBackend()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelState()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelSetState()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelInstanceName()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelInstanceKind()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelInstanceDeviceId()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelInstanceModel()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelInstanceState()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelInstanceSetState()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelInstanceReportStatistics()
{
}
TRITONBACKEND_DECLSPEC void
TRITONBACKEND_ModelInstanceReportBatchStatistics()
{
}
} /* extern "C" */
