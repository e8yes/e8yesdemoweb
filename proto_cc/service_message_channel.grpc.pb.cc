// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service_message_channel.proto

#include "service_message_channel.pb.h"
#include "service_message_channel.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace e8 {

static const char* MessageChannelService_method_names[] = {
  "/e8.MessageChannelService/CreateMessageChannel",
  "/e8.MessageChannelService/UpdateMessageChannel",
  "/e8.MessageChannelService/AddUserToMessageChannel",
  "/e8.MessageChannelService/GetMessageChannelKey",
  "/e8.MessageChannelService/LeaveMessageChannel",
  "/e8.MessageChannelService/GetJoinedInMessageChannels",
  "/e8.MessageChannelService/GetMessageChannelMembers",
};

std::unique_ptr< MessageChannelService::Stub> MessageChannelService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< MessageChannelService::Stub> stub(new MessageChannelService::Stub(channel));
  return stub;
}

MessageChannelService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_CreateMessageChannel_(MessageChannelService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_UpdateMessageChannel_(MessageChannelService_method_names[1], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_AddUserToMessageChannel_(MessageChannelService_method_names[2], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetMessageChannelKey_(MessageChannelService_method_names[3], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_LeaveMessageChannel_(MessageChannelService_method_names[4], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetJoinedInMessageChannels_(MessageChannelService_method_names[5], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetMessageChannelMembers_(MessageChannelService_method_names[6], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status MessageChannelService::Stub::CreateMessageChannel(::grpc::ClientContext* context, const ::e8::CreateMessageChannelRequest& request, ::e8::CreateMessageChannelResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_CreateMessageChannel_, context, request, response);
}

void MessageChannelService::Stub::experimental_async::CreateMessageChannel(::grpc::ClientContext* context, const ::e8::CreateMessageChannelRequest* request, ::e8::CreateMessageChannelResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_CreateMessageChannel_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::CreateMessageChannelResponse>* MessageChannelService::Stub::AsyncCreateMessageChannelRaw(::grpc::ClientContext* context, const ::e8::CreateMessageChannelRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::CreateMessageChannelResponse>::Create(channel_.get(), cq, rpcmethod_CreateMessageChannel_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::CreateMessageChannelResponse>* MessageChannelService::Stub::PrepareAsyncCreateMessageChannelRaw(::grpc::ClientContext* context, const ::e8::CreateMessageChannelRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::CreateMessageChannelResponse>::Create(channel_.get(), cq, rpcmethod_CreateMessageChannel_, context, request, false);
}

::grpc::Status MessageChannelService::Stub::UpdateMessageChannel(::grpc::ClientContext* context, const ::e8::UpdateMessageChannelRequest& request, ::e8::UpdateMessageChannelResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_UpdateMessageChannel_, context, request, response);
}

void MessageChannelService::Stub::experimental_async::UpdateMessageChannel(::grpc::ClientContext* context, const ::e8::UpdateMessageChannelRequest* request, ::e8::UpdateMessageChannelResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_UpdateMessageChannel_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::UpdateMessageChannelResponse>* MessageChannelService::Stub::AsyncUpdateMessageChannelRaw(::grpc::ClientContext* context, const ::e8::UpdateMessageChannelRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::UpdateMessageChannelResponse>::Create(channel_.get(), cq, rpcmethod_UpdateMessageChannel_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::UpdateMessageChannelResponse>* MessageChannelService::Stub::PrepareAsyncUpdateMessageChannelRaw(::grpc::ClientContext* context, const ::e8::UpdateMessageChannelRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::UpdateMessageChannelResponse>::Create(channel_.get(), cq, rpcmethod_UpdateMessageChannel_, context, request, false);
}

::grpc::Status MessageChannelService::Stub::AddUserToMessageChannel(::grpc::ClientContext* context, const ::e8::AddUserToMessageChannelRequest& request, ::e8::AddUserToMessageChannelResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_AddUserToMessageChannel_, context, request, response);
}

void MessageChannelService::Stub::experimental_async::AddUserToMessageChannel(::grpc::ClientContext* context, const ::e8::AddUserToMessageChannelRequest* request, ::e8::AddUserToMessageChannelResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_AddUserToMessageChannel_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::AddUserToMessageChannelResponse>* MessageChannelService::Stub::AsyncAddUserToMessageChannelRaw(::grpc::ClientContext* context, const ::e8::AddUserToMessageChannelRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::AddUserToMessageChannelResponse>::Create(channel_.get(), cq, rpcmethod_AddUserToMessageChannel_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::AddUserToMessageChannelResponse>* MessageChannelService::Stub::PrepareAsyncAddUserToMessageChannelRaw(::grpc::ClientContext* context, const ::e8::AddUserToMessageChannelRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::AddUserToMessageChannelResponse>::Create(channel_.get(), cq, rpcmethod_AddUserToMessageChannel_, context, request, false);
}

::grpc::Status MessageChannelService::Stub::GetMessageChannelKey(::grpc::ClientContext* context, const ::e8::GetMessageChannelKeyRequest& request, ::e8::GetMessageChannelKeyResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetMessageChannelKey_, context, request, response);
}

void MessageChannelService::Stub::experimental_async::GetMessageChannelKey(::grpc::ClientContext* context, const ::e8::GetMessageChannelKeyRequest* request, ::e8::GetMessageChannelKeyResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetMessageChannelKey_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::GetMessageChannelKeyResponse>* MessageChannelService::Stub::AsyncGetMessageChannelKeyRaw(::grpc::ClientContext* context, const ::e8::GetMessageChannelKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetMessageChannelKeyResponse>::Create(channel_.get(), cq, rpcmethod_GetMessageChannelKey_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::GetMessageChannelKeyResponse>* MessageChannelService::Stub::PrepareAsyncGetMessageChannelKeyRaw(::grpc::ClientContext* context, const ::e8::GetMessageChannelKeyRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetMessageChannelKeyResponse>::Create(channel_.get(), cq, rpcmethod_GetMessageChannelKey_, context, request, false);
}

::grpc::Status MessageChannelService::Stub::LeaveMessageChannel(::grpc::ClientContext* context, const ::e8::LeaveMessageChannelRequest& request, ::e8::LeaveMessageChannelResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_LeaveMessageChannel_, context, request, response);
}

void MessageChannelService::Stub::experimental_async::LeaveMessageChannel(::grpc::ClientContext* context, const ::e8::LeaveMessageChannelRequest* request, ::e8::LeaveMessageChannelResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_LeaveMessageChannel_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::LeaveMessageChannelResponse>* MessageChannelService::Stub::AsyncLeaveMessageChannelRaw(::grpc::ClientContext* context, const ::e8::LeaveMessageChannelRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::LeaveMessageChannelResponse>::Create(channel_.get(), cq, rpcmethod_LeaveMessageChannel_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::LeaveMessageChannelResponse>* MessageChannelService::Stub::PrepareAsyncLeaveMessageChannelRaw(::grpc::ClientContext* context, const ::e8::LeaveMessageChannelRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::LeaveMessageChannelResponse>::Create(channel_.get(), cq, rpcmethod_LeaveMessageChannel_, context, request, false);
}

::grpc::Status MessageChannelService::Stub::GetJoinedInMessageChannels(::grpc::ClientContext* context, const ::e8::GetJoinedInMessageChannelsRequest& request, ::e8::GetJoinedInMessageChannelsResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetJoinedInMessageChannels_, context, request, response);
}

void MessageChannelService::Stub::experimental_async::GetJoinedInMessageChannels(::grpc::ClientContext* context, const ::e8::GetJoinedInMessageChannelsRequest* request, ::e8::GetJoinedInMessageChannelsResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetJoinedInMessageChannels_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::GetJoinedInMessageChannelsResponse>* MessageChannelService::Stub::AsyncGetJoinedInMessageChannelsRaw(::grpc::ClientContext* context, const ::e8::GetJoinedInMessageChannelsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetJoinedInMessageChannelsResponse>::Create(channel_.get(), cq, rpcmethod_GetJoinedInMessageChannels_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::GetJoinedInMessageChannelsResponse>* MessageChannelService::Stub::PrepareAsyncGetJoinedInMessageChannelsRaw(::grpc::ClientContext* context, const ::e8::GetJoinedInMessageChannelsRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetJoinedInMessageChannelsResponse>::Create(channel_.get(), cq, rpcmethod_GetJoinedInMessageChannels_, context, request, false);
}

::grpc::Status MessageChannelService::Stub::GetMessageChannelMembers(::grpc::ClientContext* context, const ::e8::GetMessageChannelMembersRequest& request, ::e8::GetMessageChannelMembersResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_GetMessageChannelMembers_, context, request, response);
}

void MessageChannelService::Stub::experimental_async::GetMessageChannelMembers(::grpc::ClientContext* context, const ::e8::GetMessageChannelMembersRequest* request, ::e8::GetMessageChannelMembersResponse* response, std::function<void(::grpc::Status)> f) {
  return ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_GetMessageChannelMembers_, context, request, response, std::move(f));
}

::grpc::ClientAsyncResponseReader< ::e8::GetMessageChannelMembersResponse>* MessageChannelService::Stub::AsyncGetMessageChannelMembersRaw(::grpc::ClientContext* context, const ::e8::GetMessageChannelMembersRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetMessageChannelMembersResponse>::Create(channel_.get(), cq, rpcmethod_GetMessageChannelMembers_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::e8::GetMessageChannelMembersResponse>* MessageChannelService::Stub::PrepareAsyncGetMessageChannelMembersRaw(::grpc::ClientContext* context, const ::e8::GetMessageChannelMembersRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::e8::GetMessageChannelMembersResponse>::Create(channel_.get(), cq, rpcmethod_GetMessageChannelMembers_, context, request, false);
}

MessageChannelService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MessageChannelService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MessageChannelService::Service, ::e8::CreateMessageChannelRequest, ::e8::CreateMessageChannelResponse>(
          std::mem_fn(&MessageChannelService::Service::CreateMessageChannel), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MessageChannelService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MessageChannelService::Service, ::e8::UpdateMessageChannelRequest, ::e8::UpdateMessageChannelResponse>(
          std::mem_fn(&MessageChannelService::Service::UpdateMessageChannel), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MessageChannelService_method_names[2],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MessageChannelService::Service, ::e8::AddUserToMessageChannelRequest, ::e8::AddUserToMessageChannelResponse>(
          std::mem_fn(&MessageChannelService::Service::AddUserToMessageChannel), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MessageChannelService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MessageChannelService::Service, ::e8::GetMessageChannelKeyRequest, ::e8::GetMessageChannelKeyResponse>(
          std::mem_fn(&MessageChannelService::Service::GetMessageChannelKey), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MessageChannelService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MessageChannelService::Service, ::e8::LeaveMessageChannelRequest, ::e8::LeaveMessageChannelResponse>(
          std::mem_fn(&MessageChannelService::Service::LeaveMessageChannel), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MessageChannelService_method_names[5],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MessageChannelService::Service, ::e8::GetJoinedInMessageChannelsRequest, ::e8::GetJoinedInMessageChannelsResponse>(
          std::mem_fn(&MessageChannelService::Service::GetJoinedInMessageChannels), this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      MessageChannelService_method_names[6],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< MessageChannelService::Service, ::e8::GetMessageChannelMembersRequest, ::e8::GetMessageChannelMembersResponse>(
          std::mem_fn(&MessageChannelService::Service::GetMessageChannelMembers), this)));
}

MessageChannelService::Service::~Service() {
}

::grpc::Status MessageChannelService::Service::CreateMessageChannel(::grpc::ServerContext* context, const ::e8::CreateMessageChannelRequest* request, ::e8::CreateMessageChannelResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MessageChannelService::Service::UpdateMessageChannel(::grpc::ServerContext* context, const ::e8::UpdateMessageChannelRequest* request, ::e8::UpdateMessageChannelResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MessageChannelService::Service::AddUserToMessageChannel(::grpc::ServerContext* context, const ::e8::AddUserToMessageChannelRequest* request, ::e8::AddUserToMessageChannelResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MessageChannelService::Service::GetMessageChannelKey(::grpc::ServerContext* context, const ::e8::GetMessageChannelKeyRequest* request, ::e8::GetMessageChannelKeyResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MessageChannelService::Service::LeaveMessageChannel(::grpc::ServerContext* context, const ::e8::LeaveMessageChannelRequest* request, ::e8::LeaveMessageChannelResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MessageChannelService::Service::GetJoinedInMessageChannels(::grpc::ServerContext* context, const ::e8::GetJoinedInMessageChannelsRequest* request, ::e8::GetJoinedInMessageChannelsResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status MessageChannelService::Service::GetMessageChannelMembers(::grpc::ServerContext* context, const ::e8::GetMessageChannelMembersRequest* request, ::e8::GetMessageChannelMembersResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace e8

