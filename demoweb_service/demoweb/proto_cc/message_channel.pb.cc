// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: message_channel.proto

#include "message_channel.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// This is a temporary google only hack
#ifdef GOOGLE_PROTOBUF_ENFORCE_UNIQUENESS
#include "third_party/protobuf/version.h"
#endif
// @@protoc_insertion_point(includes)

namespace protobuf_file_2eproto {
extern PROTOBUF_INTERNAL_EXPORT_protobuf_file_2eproto ::google::protobuf::internal::SCCInfo<0> scc_info_FileTokenAccess;
}  // namespace protobuf_file_2eproto
namespace e8 {
class MessageChannelDefaultTypeInternal {
 public:
  ::google::protobuf::internal::ExplicitlyConstructed<MessageChannel>
      _instance;
} _MessageChannel_default_instance_;
}  // namespace e8
namespace protobuf_message_5fchannel_2eproto {
static void InitDefaultsMessageChannel() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::e8::_MessageChannel_default_instance_;
    new (ptr) ::e8::MessageChannel();
    ::google::protobuf::internal::OnShutdownDestroyMessage(ptr);
  }
  ::e8::MessageChannel::InitAsDefaultInstance();
}

::google::protobuf::internal::SCCInfo<1> scc_info_MessageChannel =
    {{ATOMIC_VAR_INIT(::google::protobuf::internal::SCCInfoBase::kUninitialized), 1, InitDefaultsMessageChannel}, {
      &protobuf_file_2eproto::scc_info_FileTokenAccess.base,}};

void InitDefaults() {
  ::google::protobuf::internal::InitSCC(&scc_info_MessageChannel.base);
}

::google::protobuf::Metadata file_level_metadata[1];

const ::google::protobuf::uint32 TableStruct::offsets[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::MessageChannel, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::MessageChannel, channel_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::MessageChannel, admin_user_id_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::MessageChannel, title_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::MessageChannel, avatar_readonly_access_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::MessageChannel, avatar_preview_readonly_access_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::MessageChannel, created_at_),
  GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(::e8::MessageChannel, joined_at_),
};
static const ::google::protobuf::internal::MigrationSchema schemas[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::e8::MessageChannel)},
};

static ::google::protobuf::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::google::protobuf::Message*>(&::e8::_MessageChannel_default_instance_),
};

void protobuf_AssignDescriptors() {
  AddDescriptors();
  AssignDescriptors(
      "message_channel.proto", schemas, file_default_instances, TableStruct::offsets,
      file_level_metadata, NULL, NULL);
}

void protobuf_AssignDescriptorsOnce() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, protobuf_AssignDescriptors);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_PROTOBUF_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::internal::RegisterAllTypes(file_level_metadata, 1);
}

void AddDescriptorsImpl() {
  InitDefaults();
  static const char descriptor[] GOOGLE_PROTOBUF_ATTRIBUTE_SECTION_VARIABLE(protodesc_cold) = {
      "\n\025message_channel.proto\022\002e8\032\nfile.proto\""
      "\343\001\n\016MessageChannel\022\022\n\nchannel_id\030\001 \001(\003\022\025"
      "\n\radmin_user_id\030\002 \001(\003\022\r\n\005title\030\003 \001(\t\0223\n\026"
      "avatar_readonly_access\030\004 \001(\0132\023.e8.FileTo"
      "kenAccess\022;\n\036avatar_preview_readonly_acc"
      "ess\030\005 \001(\0132\023.e8.FileTokenAccess\022\022\n\ncreate"
      "d_at\030\006 \001(\003\022\021\n\tjoined_at\030\007 \001(\003b\006proto3"
  };
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
      descriptor, 277);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "message_channel.proto", &protobuf_RegisterTypes);
  ::protobuf_file_2eproto::AddDescriptors();
}

void AddDescriptors() {
  static ::google::protobuf::internal::once_flag once;
  ::google::protobuf::internal::call_once(once, AddDescriptorsImpl);
}
// Force AddDescriptors() to be called at dynamic initialization time.
struct StaticDescriptorInitializer {
  StaticDescriptorInitializer() {
    AddDescriptors();
  }
} static_descriptor_initializer;
}  // namespace protobuf_message_5fchannel_2eproto
namespace e8 {

// ===================================================================

void MessageChannel::InitAsDefaultInstance() {
  ::e8::_MessageChannel_default_instance_._instance.get_mutable()->avatar_readonly_access_ = const_cast< ::e8::FileTokenAccess*>(
      ::e8::FileTokenAccess::internal_default_instance());
  ::e8::_MessageChannel_default_instance_._instance.get_mutable()->avatar_preview_readonly_access_ = const_cast< ::e8::FileTokenAccess*>(
      ::e8::FileTokenAccess::internal_default_instance());
}
void MessageChannel::clear_avatar_readonly_access() {
  if (GetArenaNoVirtual() == NULL && avatar_readonly_access_ != NULL) {
    delete avatar_readonly_access_;
  }
  avatar_readonly_access_ = NULL;
}
void MessageChannel::clear_avatar_preview_readonly_access() {
  if (GetArenaNoVirtual() == NULL && avatar_preview_readonly_access_ != NULL) {
    delete avatar_preview_readonly_access_;
  }
  avatar_preview_readonly_access_ = NULL;
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int MessageChannel::kChannelIdFieldNumber;
const int MessageChannel::kAdminUserIdFieldNumber;
const int MessageChannel::kTitleFieldNumber;
const int MessageChannel::kAvatarReadonlyAccessFieldNumber;
const int MessageChannel::kAvatarPreviewReadonlyAccessFieldNumber;
const int MessageChannel::kCreatedAtFieldNumber;
const int MessageChannel::kJoinedAtFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

MessageChannel::MessageChannel()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  ::google::protobuf::internal::InitSCC(
      &protobuf_message_5fchannel_2eproto::scc_info_MessageChannel.base);
  SharedCtor();
  // @@protoc_insertion_point(constructor:e8.MessageChannel)
}
MessageChannel::MessageChannel(const MessageChannel& from)
  : ::google::protobuf::Message(),
      _internal_metadata_(NULL) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  title_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (from.title().size() > 0) {
    title_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.title_);
  }
  if (from.has_avatar_readonly_access()) {
    avatar_readonly_access_ = new ::e8::FileTokenAccess(*from.avatar_readonly_access_);
  } else {
    avatar_readonly_access_ = NULL;
  }
  if (from.has_avatar_preview_readonly_access()) {
    avatar_preview_readonly_access_ = new ::e8::FileTokenAccess(*from.avatar_preview_readonly_access_);
  } else {
    avatar_preview_readonly_access_ = NULL;
  }
  ::memcpy(&channel_id_, &from.channel_id_,
    static_cast<size_t>(reinterpret_cast<char*>(&joined_at_) -
    reinterpret_cast<char*>(&channel_id_)) + sizeof(joined_at_));
  // @@protoc_insertion_point(copy_constructor:e8.MessageChannel)
}

void MessageChannel::SharedCtor() {
  title_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&avatar_readonly_access_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&joined_at_) -
      reinterpret_cast<char*>(&avatar_readonly_access_)) + sizeof(joined_at_));
}

MessageChannel::~MessageChannel() {
  // @@protoc_insertion_point(destructor:e8.MessageChannel)
  SharedDtor();
}

void MessageChannel::SharedDtor() {
  title_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (this != internal_default_instance()) delete avatar_readonly_access_;
  if (this != internal_default_instance()) delete avatar_preview_readonly_access_;
}

void MessageChannel::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const ::google::protobuf::Descriptor* MessageChannel::descriptor() {
  ::protobuf_message_5fchannel_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_message_5fchannel_2eproto::file_level_metadata[kIndexInFileMessages].descriptor;
}

const MessageChannel& MessageChannel::default_instance() {
  ::google::protobuf::internal::InitSCC(&protobuf_message_5fchannel_2eproto::scc_info_MessageChannel.base);
  return *internal_default_instance();
}


void MessageChannel::Clear() {
// @@protoc_insertion_point(message_clear_start:e8.MessageChannel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  title_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  if (GetArenaNoVirtual() == NULL && avatar_readonly_access_ != NULL) {
    delete avatar_readonly_access_;
  }
  avatar_readonly_access_ = NULL;
  if (GetArenaNoVirtual() == NULL && avatar_preview_readonly_access_ != NULL) {
    delete avatar_preview_readonly_access_;
  }
  avatar_preview_readonly_access_ = NULL;
  ::memset(&channel_id_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&joined_at_) -
      reinterpret_cast<char*>(&channel_id_)) + sizeof(joined_at_));
  _internal_metadata_.Clear();
}

bool MessageChannel::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:e8.MessageChannel)
  for (;;) {
    ::std::pair<::google::protobuf::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // int64 channel_id = 1;
      case 1: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(8u /* 8 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &channel_id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 admin_user_id = 2;
      case 2: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(16u /* 16 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &admin_user_id_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // string title = 3;
      case 3: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(26u /* 26 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_title()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->title().data(), static_cast<int>(this->title().length()),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "e8.MessageChannel.title"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .e8.FileTokenAccess avatar_readonly_access = 4;
      case 4: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(34u /* 34 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_avatar_readonly_access()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // .e8.FileTokenAccess avatar_preview_readonly_access = 5;
      case 5: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(42u /* 42 & 0xFF */)) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessage(
               input, mutable_avatar_preview_readonly_access()));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 created_at = 6;
      case 6: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(48u /* 48 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &created_at_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // int64 joined_at = 7;
      case 7: {
        if (static_cast< ::google::protobuf::uint8>(tag) ==
            static_cast< ::google::protobuf::uint8>(56u /* 56 & 0xFF */)) {

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &joined_at_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:e8.MessageChannel)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:e8.MessageChannel)
  return false;
#undef DO_
}

void MessageChannel::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:e8.MessageChannel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 channel_id = 1;
  if (this->channel_id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->channel_id(), output);
  }

  // int64 admin_user_id = 2;
  if (this->admin_user_id() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->admin_user_id(), output);
  }

  // string title = 3;
  if (this->title().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->title().data(), static_cast<int>(this->title().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "e8.MessageChannel.title");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->title(), output);
  }

  // .e8.FileTokenAccess avatar_readonly_access = 4;
  if (this->has_avatar_readonly_access()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      4, this->_internal_avatar_readonly_access(), output);
  }

  // .e8.FileTokenAccess avatar_preview_readonly_access = 5;
  if (this->has_avatar_preview_readonly_access()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      5, this->_internal_avatar_preview_readonly_access(), output);
  }

  // int64 created_at = 6;
  if (this->created_at() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(6, this->created_at(), output);
  }

  // int64 joined_at = 7;
  if (this->joined_at() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(7, this->joined_at(), output);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), output);
  }
  // @@protoc_insertion_point(serialize_end:e8.MessageChannel)
}

::google::protobuf::uint8* MessageChannel::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:e8.MessageChannel)
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // int64 channel_id = 1;
  if (this->channel_id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->channel_id(), target);
  }

  // int64 admin_user_id = 2;
  if (this->admin_user_id() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->admin_user_id(), target);
  }

  // string title = 3;
  if (this->title().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->title().data(), static_cast<int>(this->title().length()),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "e8.MessageChannel.title");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->title(), target);
  }

  // .e8.FileTokenAccess avatar_readonly_access = 4;
  if (this->has_avatar_readonly_access()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        4, this->_internal_avatar_readonly_access(), deterministic, target);
  }

  // .e8.FileTokenAccess avatar_preview_readonly_access = 5;
  if (this->has_avatar_preview_readonly_access()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageToArray(
        5, this->_internal_avatar_preview_readonly_access(), deterministic, target);
  }

  // int64 created_at = 6;
  if (this->created_at() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(6, this->created_at(), target);
  }

  // int64 joined_at = 7;
  if (this->joined_at() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(7, this->joined_at(), target);
  }

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:e8.MessageChannel)
  return target;
}

size_t MessageChannel::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:e8.MessageChannel)
  size_t total_size = 0;

  if ((_internal_metadata_.have_unknown_fields() &&  ::google::protobuf::internal::GetProto3PreserveUnknownsDefault())) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        (::google::protobuf::internal::GetProto3PreserveUnknownsDefault()   ? _internal_metadata_.unknown_fields()   : _internal_metadata_.default_instance()));
  }
  // string title = 3;
  if (this->title().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->title());
  }

  // .e8.FileTokenAccess avatar_readonly_access = 4;
  if (this->has_avatar_readonly_access()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *avatar_readonly_access_);
  }

  // .e8.FileTokenAccess avatar_preview_readonly_access = 5;
  if (this->has_avatar_preview_readonly_access()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSize(
        *avatar_preview_readonly_access_);
  }

  // int64 channel_id = 1;
  if (this->channel_id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->channel_id());
  }

  // int64 admin_user_id = 2;
  if (this->admin_user_id() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->admin_user_id());
  }

  // int64 created_at = 6;
  if (this->created_at() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->created_at());
  }

  // int64 joined_at = 7;
  if (this->joined_at() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->joined_at());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void MessageChannel::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:e8.MessageChannel)
  GOOGLE_DCHECK_NE(&from, this);
  const MessageChannel* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const MessageChannel>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:e8.MessageChannel)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:e8.MessageChannel)
    MergeFrom(*source);
  }
}

void MessageChannel::MergeFrom(const MessageChannel& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:e8.MessageChannel)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::google::protobuf::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.title().size() > 0) {

    title_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.title_);
  }
  if (from.has_avatar_readonly_access()) {
    mutable_avatar_readonly_access()->::e8::FileTokenAccess::MergeFrom(from.avatar_readonly_access());
  }
  if (from.has_avatar_preview_readonly_access()) {
    mutable_avatar_preview_readonly_access()->::e8::FileTokenAccess::MergeFrom(from.avatar_preview_readonly_access());
  }
  if (from.channel_id() != 0) {
    set_channel_id(from.channel_id());
  }
  if (from.admin_user_id() != 0) {
    set_admin_user_id(from.admin_user_id());
  }
  if (from.created_at() != 0) {
    set_created_at(from.created_at());
  }
  if (from.joined_at() != 0) {
    set_joined_at(from.joined_at());
  }
}

void MessageChannel::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:e8.MessageChannel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MessageChannel::CopyFrom(const MessageChannel& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:e8.MessageChannel)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MessageChannel::IsInitialized() const {
  return true;
}

void MessageChannel::Swap(MessageChannel* other) {
  if (other == this) return;
  InternalSwap(other);
}
void MessageChannel::InternalSwap(MessageChannel* other) {
  using std::swap;
  title_.Swap(&other->title_, &::google::protobuf::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(avatar_readonly_access_, other->avatar_readonly_access_);
  swap(avatar_preview_readonly_access_, other->avatar_preview_readonly_access_);
  swap(channel_id_, other->channel_id_);
  swap(admin_user_id_, other->admin_user_id_);
  swap(created_at_, other->created_at_);
  swap(joined_at_, other->joined_at_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
}

::google::protobuf::Metadata MessageChannel::GetMetadata() const {
  protobuf_message_5fchannel_2eproto::protobuf_AssignDescriptorsOnce();
  return ::protobuf_message_5fchannel_2eproto::file_level_metadata[kIndexInFileMessages];
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace e8
namespace google {
namespace protobuf {
template<> GOOGLE_PROTOBUF_ATTRIBUTE_NOINLINE ::e8::MessageChannel* Arena::CreateMaybeMessage< ::e8::MessageChannel >(Arena* arena) {
  return Arena::CreateInternal< ::e8::MessageChannel >(arena);
}
}  // namespace protobuf
}  // namespace google

// @@protoc_insertion_point(global_scope)