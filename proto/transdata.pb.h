// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: transdata.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_transdata_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_transdata_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021009 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h> // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_transdata_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal
{
  class AnyMetadata;
} // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_transdata_2eproto
{
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_transdata_2eproto;
namespace transdata
{
  class Topic1;
  struct Topic1DefaultTypeInternal;
  extern Topic1DefaultTypeInternal _Topic1_default_instance_;
} // namespace transdata
PROTOBUF_NAMESPACE_OPEN
template <>
::transdata::Topic1 *Arena::CreateMaybeMessage<::transdata::Topic1>(Arena *);
PROTOBUF_NAMESPACE_CLOSE
namespace transdata
{

  // ===================================================================

  class Topic1 final : public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:transdata.Topic1) */
  {
  public:
    inline Topic1() : Topic1(nullptr) {}
    ~Topic1() override;
    explicit PROTOBUF_CONSTEXPR Topic1(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

    Topic1(const Topic1 &from);
    Topic1(Topic1 &&from) noexcept
        : Topic1()
    {
      *this = ::std::move(from);
    }

    inline Topic1 &operator=(const Topic1 &from)
    {
      CopyFrom(from);
      return *this;
    }
    inline Topic1 &operator=(Topic1 &&from) noexcept
    {
      if (this == &from)
        return *this;
      if (GetOwningArena() == from.GetOwningArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
          && GetOwningArena() != nullptr
#endif // !PROTOBUF_FORCE_COPY_IN_MOVE
      )
      {
        InternalSwap(&from);
      }
      else
      {
        CopyFrom(from);
      }
      return *this;
    }

    static const ::PROTOBUF_NAMESPACE_ID::Descriptor *descriptor()
    {
      return GetDescriptor();
    }
    static const ::PROTOBUF_NAMESPACE_ID::Descriptor *GetDescriptor()
    {
      return default_instance().GetMetadata().descriptor;
    }
    static const ::PROTOBUF_NAMESPACE_ID::Reflection *GetReflection()
    {
      return default_instance().GetMetadata().reflection;
    }
    static const Topic1 &default_instance()
    {
      return *internal_default_instance();
    }
    static inline const Topic1 *internal_default_instance()
    {
      return reinterpret_cast<const Topic1 *>(
          &_Topic1_default_instance_);
    }
    static constexpr int kIndexInFileMessages =
        0;

    friend void swap(Topic1 &a, Topic1 &b)
    {
      a.Swap(&b);
    }
    inline void Swap(Topic1 *other)
    {
      if (other == this)
        return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
      if (GetOwningArena() != nullptr &&
          GetOwningArena() == other->GetOwningArena())
      {
#else  // PROTOBUF_FORCE_COPY_IN_SWAP
      if (GetOwningArena() == other->GetOwningArena())
      {
#endif // !PROTOBUF_FORCE_COPY_IN_SWAP
        InternalSwap(other);
      }
      else
      {
        ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
      }
    }
    void UnsafeArenaSwap(Topic1 *other)
    {
      if (other == this)
        return;
      GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
      InternalSwap(other);
    }

    // implements Message ----------------------------------------------

    Topic1 *New(::PROTOBUF_NAMESPACE_ID::Arena *arena = nullptr) const final
    {
      return CreateMaybeMessage<Topic1>(arena);
    }
    using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
    void CopyFrom(const Topic1 &from);
    using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
    void MergeFrom(const Topic1 &from)
    {
      Topic1::MergeImpl(*this, from);
    }

  private:
    static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message &to_msg, const ::PROTOBUF_NAMESPACE_ID::Message &from_msg);

  public:
    PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
    bool IsInitialized() const final;

    size_t ByteSizeLong() const final;
    const char *_InternalParse(const char *ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext *ctx) final;
    uint8_t *_InternalSerialize(
        uint8_t *target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream *stream) const final;
    int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
    void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena *arena, bool is_message_owned);
    void SharedDtor();
    void SetCachedSize(int size) const final;
    void InternalSwap(Topic1 *other);

  private:
    friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
    static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName()
    {
      return "transdata.Topic1";
    }

  protected:
    explicit Topic1(::PROTOBUF_NAMESPACE_ID::Arena *arena,
                    bool is_message_owned = false);

  public:
    static const ClassData _class_data_;
    const ::PROTOBUF_NAMESPACE_ID::Message::ClassData *GetClassData() const final;

    ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

    // nested types ----------------------------------------------------

    // accessors -------------------------------------------------------

    enum : int
    {
      kDataFieldNumber = 2,
      kIdFieldNumber = 1,
    };
    // repeated double data = 2;
    int data_size() const;

  private:
    int _internal_data_size() const;

  public:
    void clear_data();

  private:
    double _internal_data(int index) const;
    const ::PROTOBUF_NAMESPACE_ID::RepeatedField<double> &
    _internal_data() const;
    void _internal_add_data(double value);
    ::PROTOBUF_NAMESPACE_ID::RepeatedField<double> *
    _internal_mutable_data();

  public:
    double data(int index) const;
    void set_data(int index, double value);
    void add_data(double value);
    const ::PROTOBUF_NAMESPACE_ID::RepeatedField<double> &
    data() const;
    ::PROTOBUF_NAMESPACE_ID::RepeatedField<double> *
    mutable_data();

    // uint64 id = 1;
    void clear_id();
    uint64_t id() const;
    void set_id(uint64_t value);

  private:
    uint64_t _internal_id() const;
    void _internal_set_id(uint64_t value);

  public:
    // @@protoc_insertion_point(class_scope:transdata.Topic1)
  private:
    class _Internal;

    template <typename T>
    friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
    typedef void InternalArenaConstructable_;
    typedef void DestructorSkippable_;
    struct Impl_
    {
      ::PROTOBUF_NAMESPACE_ID::RepeatedField<double> data_;
      uint64_t id_;
      mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
    };
    union
    {
      Impl_ _impl_;
    };
    friend struct ::TableStruct_transdata_2eproto;
  };
  // ===================================================================

  // ===================================================================

#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif // __GNUC__
  // Topic1

  // uint64 id = 1;
  inline void Topic1::clear_id()
  {
    _impl_.id_ = uint64_t{0u};
  }
  inline uint64_t Topic1::_internal_id() const
  {
    return _impl_.id_;
  }
  inline uint64_t Topic1::id() const
  {
    // @@protoc_insertion_point(field_get:transdata.Topic1.id)
    return _internal_id();
  }
  inline void Topic1::_internal_set_id(uint64_t value)
  {

    _impl_.id_ = value;
  }
  inline void Topic1::set_id(uint64_t value)
  {
    _internal_set_id(value);
    // @@protoc_insertion_point(field_set:transdata.Topic1.id)
  }

  // repeated double data = 2;
  inline int Topic1::_internal_data_size() const
  {
    return _impl_.data_.size();
  }
  inline int Topic1::data_size() const
  {
    return _internal_data_size();
  }
  inline void Topic1::clear_data()
  {
    _impl_.data_.Clear();
  }
  inline double Topic1::_internal_data(int index) const
  {
    return _impl_.data_.Get(index);
  }
  inline double Topic1::data(int index) const
  {
    // @@protoc_insertion_point(field_get:transdata.Topic1.data)
    return _internal_data(index);
  }
  inline void Topic1::set_data(int index, double value)
  {
    _impl_.data_.Set(index, value);
    // @@protoc_insertion_point(field_set:transdata.Topic1.data)
  }
  inline void Topic1::_internal_add_data(double value)
  {
    _impl_.data_.Add(value);
  }
  inline void Topic1::add_data(double value)
  {
    _internal_add_data(value);
    // @@protoc_insertion_point(field_add:transdata.Topic1.data)
  }
  inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<double> &
  Topic1::_internal_data() const
  {
    return _impl_.data_;
  }
  inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField<double> &
  Topic1::data() const
  {
    // @@protoc_insertion_point(field_list:transdata.Topic1.data)
    return _internal_data();
  }
  inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<double> *
  Topic1::_internal_mutable_data()
  {
    return &_impl_.data_;
  }
  inline ::PROTOBUF_NAMESPACE_ID::RepeatedField<double> *
  Topic1::mutable_data()
  {
    // @@protoc_insertion_point(field_mutable_list:transdata.Topic1.data)
    return _internal_mutable_data();
  }

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif // __GNUC__

  // @@protoc_insertion_point(namespace_scope)

} // namespace transdata

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_transdata_2eproto
