// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transdata.proto

#include "transdata.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

namespace transdata {
PROTOBUF_CONSTEXPR Topic1::Topic1(
    ::_pbi::ConstantInitialized): _impl_{
    /*decltype(_impl_.data_)*/{}
  , /*decltype(_impl_.id_)*/uint64_t{0u}
  , /*decltype(_impl_._cached_size_)*/{}} {}
struct Topic1DefaultTypeInternal {
  PROTOBUF_CONSTEXPR Topic1DefaultTypeInternal()
      : _instance(::_pbi::ConstantInitialized{}) {}
  ~Topic1DefaultTypeInternal() {}
  union {
    Topic1 _instance;
  };
};
PROTOBUF_ATTRIBUTE_NO_DESTROY PROTOBUF_CONSTINIT PROTOBUF_ATTRIBUTE_INIT_PRIORITY1 Topic1DefaultTypeInternal _Topic1_default_instance_;
}  // namespace transdata
static ::_pb::Metadata file_level_metadata_transdata_2eproto[1];
static constexpr ::_pb::EnumDescriptor const** file_level_enum_descriptors_transdata_2eproto = nullptr;
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_transdata_2eproto = nullptr;

const uint32_t TableStruct_transdata_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::transdata::Topic1, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  ~0u,  // no _inlined_string_donated_
  PROTOBUF_FIELD_OFFSET(::transdata::Topic1, _impl_.id_),
  PROTOBUF_FIELD_OFFSET(::transdata::Topic1, _impl_.data_),
};
static const ::_pbi::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, -1, sizeof(::transdata::Topic1)},
};

static const ::_pb::Message* const file_default_instances[] = {
  &::transdata::_Topic1_default_instance_._instance,
};

const char descriptor_table_protodef_transdata_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017transdata.proto\022\ttransdata\"\"\n\006Topic1\022\n"
  "\n\002id\030\001 \001(\004\022\014\n\004data\030\002 \003(\001b\006proto3"
  ;
static ::_pbi::once_flag descriptor_table_transdata_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_transdata_2eproto = {
    false, false, 72, descriptor_table_protodef_transdata_2eproto,
    "transdata.proto",
    &descriptor_table_transdata_2eproto_once, nullptr, 0, 1,
    schemas, file_default_instances, TableStruct_transdata_2eproto::offsets,
    file_level_metadata_transdata_2eproto, file_level_enum_descriptors_transdata_2eproto,
    file_level_service_descriptors_transdata_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_transdata_2eproto_getter() {
  return &descriptor_table_transdata_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_transdata_2eproto(&descriptor_table_transdata_2eproto);
namespace transdata {

// ===================================================================

class Topic1::_Internal {
 public:
};

Topic1::Topic1(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                         bool is_message_owned)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena, is_message_owned) {
  SharedCtor(arena, is_message_owned);
  // @@protoc_insertion_point(arena_constructor:transdata.Topic1)
}
Topic1::Topic1(const Topic1& from)
  : ::PROTOBUF_NAMESPACE_ID::Message() {
  Topic1* const _this = this; (void)_this;
  new (&_impl_) Impl_{
      decltype(_impl_.data_){from._impl_.data_}
    , decltype(_impl_.id_){}
    , /*decltype(_impl_._cached_size_)*/{}};

  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  _this->_impl_.id_ = from._impl_.id_;
  // @@protoc_insertion_point(copy_constructor:transdata.Topic1)
}

inline void Topic1::SharedCtor(
    ::_pb::Arena* arena, bool is_message_owned) {
  (void)arena;
  (void)is_message_owned;
  new (&_impl_) Impl_{
      decltype(_impl_.data_){arena}
    , decltype(_impl_.id_){uint64_t{0u}}
    , /*decltype(_impl_._cached_size_)*/{}
  };
}

Topic1::~Topic1() {
  // @@protoc_insertion_point(destructor:transdata.Topic1)
  if (auto *arena = _internal_metadata_.DeleteReturnArena<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>()) {
  (void)arena;
    return;
  }
  SharedDtor();
}

inline void Topic1::SharedDtor() {
  GOOGLE_DCHECK(GetArenaForAllocation() == nullptr);
  _impl_.data_.~RepeatedField();
}

void Topic1::SetCachedSize(int size) const {
  _impl_._cached_size_.Set(size);
}

void Topic1::Clear() {
// @@protoc_insertion_point(message_clear_start:transdata.Topic1)
  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  _impl_.data_.Clear();
  _impl_.id_ = uint64_t{0u};
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* Topic1::_InternalParse(const char* ptr, ::_pbi::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  while (!ctx->Done(&ptr)) {
    uint32_t tag;
    ptr = ::_pbi::ReadTag(ptr, &tag);
    switch (tag >> 3) {
      // uint64 id = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 8)) {
          _impl_.id_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint64(&ptr);
          CHK_(ptr);
        } else
          goto handle_unusual;
        continue;
      // repeated double data = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<uint8_t>(tag) == 18)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::PackedDoubleParser(_internal_mutable_data(), ptr, ctx);
          CHK_(ptr);
        } else if (static_cast<uint8_t>(tag) == 17) {
          _internal_add_data(::PROTOBUF_NAMESPACE_ID::internal::UnalignedLoad<double>(ptr));
          ptr += sizeof(double);
        } else
          goto handle_unusual;
        continue;
      default:
        goto handle_unusual;
    }  // switch
  handle_unusual:
    if ((tag == 0) || ((tag & 7) == 4)) {
      CHK_(ptr);
      ctx->SetLastTag(tag);
      goto message_done;
    }
    ptr = UnknownFieldParse(
        tag,
        _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
        ptr, ctx);
    CHK_(ptr != nullptr);
  }  // while
message_done:
  return ptr;
failure:
  ptr = nullptr;
  goto message_done;
#undef CHK_
}

uint8_t* Topic1::_InternalSerialize(
    uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:transdata.Topic1)
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  // uint64 id = 1;
  if (this->_internal_id() != 0) {
    target = stream->EnsureSpace(target);
    target = ::_pbi::WireFormatLite::WriteUInt64ToArray(1, this->_internal_id(), target);
  }

  // repeated double data = 2;
  if (this->_internal_data_size() > 0) {
    target = stream->WriteFixedPacked(2, _internal_data(), target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::_pbi::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:transdata.Topic1)
  return target;
}

size_t Topic1::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:transdata.Topic1)
  size_t total_size = 0;

  uint32_t cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated double data = 2;
  {
    unsigned int count = static_cast<unsigned int>(this->_internal_data_size());
    size_t data_size = 8UL * count;
    if (data_size > 0) {
      total_size += 1 +
        ::_pbi::WireFormatLite::Int32Size(static_cast<int32_t>(data_size));
    }
    total_size += data_size;
  }

  // uint64 id = 1;
  if (this->_internal_id() != 0) {
    total_size += ::_pbi::WireFormatLite::UInt64SizePlusOne(this->_internal_id());
  }

  return MaybeComputeUnknownFieldsSize(total_size, &_impl_._cached_size_);
}

const ::PROTOBUF_NAMESPACE_ID::Message::ClassData Topic1::_class_data_ = {
    ::PROTOBUF_NAMESPACE_ID::Message::CopyWithSourceCheck,
    Topic1::MergeImpl
};
const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*Topic1::GetClassData() const { return &_class_data_; }


void Topic1::MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg) {
  auto* const _this = static_cast<Topic1*>(&to_msg);
  auto& from = static_cast<const Topic1&>(from_msg);
  // @@protoc_insertion_point(class_specific_merge_from_start:transdata.Topic1)
  GOOGLE_DCHECK_NE(&from, _this);
  uint32_t cached_has_bits = 0;
  (void) cached_has_bits;

  _this->_impl_.data_.MergeFrom(from._impl_.data_);
  if (from._internal_id() != 0) {
    _this->_internal_set_id(from._internal_id());
  }
  _this->_internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
}

void Topic1::CopyFrom(const Topic1& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:transdata.Topic1)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Topic1::IsInitialized() const {
  return true;
}

void Topic1::InternalSwap(Topic1* other) {
  using std::swap;
  _internal_metadata_.InternalSwap(&other->_internal_metadata_);
  _impl_.data_.InternalSwap(&other->_impl_.data_);
  swap(_impl_.id_, other->_impl_.id_);
}

::PROTOBUF_NAMESPACE_ID::Metadata Topic1::GetMetadata() const {
  return ::_pbi::AssignDescriptors(
      &descriptor_table_transdata_2eproto_getter, &descriptor_table_transdata_2eproto_once,
      file_level_metadata_transdata_2eproto[0]);
}

// @@protoc_insertion_point(namespace_scope)
}  // namespace transdata
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::transdata::Topic1*
Arena::CreateMaybeMessage< ::transdata::Topic1 >(Arena* arena) {
  return Arena::CreateMessageInternal< ::transdata::Topic1 >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
