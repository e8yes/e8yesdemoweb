# Generated by the gRPC Python protocol compiler plugin. DO NOT EDIT!
import grpc

import service_chat_message_pb2 as service__chat__message__pb2


class ChatMessageServiceStub(object):
  # missing associated documentation comment in .proto file
  pass

  def __init__(self, channel):
    """Constructor.

    Args:
      channel: A grpc.Channel.
    """
    self.SendChatMessage = channel.unary_unary(
        '/e8.ChatMessageService/SendChatMessage',
        request_serializer=service__chat__message__pb2.SendChatMessageRequest.SerializeToString,
        response_deserializer=service__chat__message__pb2.SendChatMessageResponse.FromString,
        )
    self.GetChatMessage = channel.unary_unary(
        '/e8.ChatMessageService/GetChatMessage',
        request_serializer=service__chat__message__pb2.GetChatMessageRequest.SerializeToString,
        response_deserializer=service__chat__message__pb2.GetChatMessageResponse.FromString,
        )


class ChatMessageServiceServicer(object):
  # missing associated documentation comment in .proto file
  pass

  def SendChatMessage(self, request, context):
    """Send a chat message to the message channel where the logged-in user
    is the sender.
    """
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')

  def GetChatMessage(self, request, context):
    """Get a history of the chat messages in the specified message channel.
    """
    context.set_code(grpc.StatusCode.UNIMPLEMENTED)
    context.set_details('Method not implemented!')
    raise NotImplementedError('Method not implemented!')


def add_ChatMessageServiceServicer_to_server(servicer, server):
  rpc_method_handlers = {
      'SendChatMessage': grpc.unary_unary_rpc_method_handler(
          servicer.SendChatMessage,
          request_deserializer=service__chat__message__pb2.SendChatMessageRequest.FromString,
          response_serializer=service__chat__message__pb2.SendChatMessageResponse.SerializeToString,
      ),
      'GetChatMessage': grpc.unary_unary_rpc_method_handler(
          servicer.GetChatMessage,
          request_deserializer=service__chat__message__pb2.GetChatMessageRequest.FromString,
          response_serializer=service__chat__message__pb2.GetChatMessageResponse.SerializeToString,
      ),
  }
  generic_handler = grpc.method_handlers_generic_handler(
      'e8.ChatMessageService', rpc_method_handlers)
  server.add_generic_rpc_handlers((generic_handler,))
