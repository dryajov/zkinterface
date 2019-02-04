// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_GADGET_GADGET_H_
#define FLATBUFFERS_GENERATED_GADGET_GADGET_H_

#include "flatbuffers/flatbuffers.h"

namespace Gadget {

struct Root;

struct VariableValues;

struct BilinearConstraint;

struct GadgetInstance;

struct CustomKeyValue;

struct R1CSConstraints;

struct AssignedVariables;

struct ComponentCall;

struct Witness;

struct ComponentReturn;

enum Message {
  Message_NONE = 0,
  Message_R1CSConstraints = 1,
  Message_AssignedVariables = 2,
  Message_ComponentCall = 3,
  Message_ComponentReturn = 4,
  Message_MIN = Message_NONE,
  Message_MAX = Message_ComponentReturn
};

inline const Message (&EnumValuesMessage())[5] {
  static const Message values[] = {
    Message_NONE,
    Message_R1CSConstraints,
    Message_AssignedVariables,
    Message_ComponentCall,
    Message_ComponentReturn
  };
  return values;
}

inline const char * const *EnumNamesMessage() {
  static const char * const names[] = {
    "NONE",
    "R1CSConstraints",
    "AssignedVariables",
    "ComponentCall",
    "ComponentReturn",
    nullptr
  };
  return names;
}

inline const char *EnumNameMessage(Message e) {
  if (e < Message_NONE || e > Message_ComponentReturn) return "";
  const size_t index = static_cast<int>(e);
  return EnumNamesMessage()[index];
}

template<typename T> struct MessageTraits {
  static const Message enum_value = Message_NONE;
};

template<> struct MessageTraits<R1CSConstraints> {
  static const Message enum_value = Message_R1CSConstraints;
};

template<> struct MessageTraits<AssignedVariables> {
  static const Message enum_value = Message_AssignedVariables;
};

template<> struct MessageTraits<ComponentCall> {
  static const Message enum_value = Message_ComponentCall;
};

template<> struct MessageTraits<ComponentReturn> {
  static const Message enum_value = Message_ComponentReturn;
};

bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type);
bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

struct Root FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_MESSAGE_TYPE = 4,
    VT_MESSAGE = 6
  };
  Message message_type() const {
    return static_cast<Message>(GetField<uint8_t>(VT_MESSAGE_TYPE, 0));
  }
  const void *message() const {
    return GetPointer<const void *>(VT_MESSAGE);
  }
  template<typename T> const T *message_as() const;
  const R1CSConstraints *message_as_R1CSConstraints() const {
    return message_type() == Message_R1CSConstraints ? static_cast<const R1CSConstraints *>(message()) : nullptr;
  }
  const AssignedVariables *message_as_AssignedVariables() const {
    return message_type() == Message_AssignedVariables ? static_cast<const AssignedVariables *>(message()) : nullptr;
  }
  const ComponentCall *message_as_ComponentCall() const {
    return message_type() == Message_ComponentCall ? static_cast<const ComponentCall *>(message()) : nullptr;
  }
  const ComponentReturn *message_as_ComponentReturn() const {
    return message_type() == Message_ComponentReturn ? static_cast<const ComponentReturn *>(message()) : nullptr;
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_MESSAGE_TYPE) &&
           VerifyOffset(verifier, VT_MESSAGE) &&
           VerifyMessage(verifier, message(), message_type()) &&
           verifier.EndTable();
  }
};

template<> inline const R1CSConstraints *Root::message_as<R1CSConstraints>() const {
  return message_as_R1CSConstraints();
}

template<> inline const AssignedVariables *Root::message_as<AssignedVariables>() const {
  return message_as_AssignedVariables();
}

template<> inline const ComponentCall *Root::message_as<ComponentCall>() const {
  return message_as_ComponentCall();
}

template<> inline const ComponentReturn *Root::message_as<ComponentReturn>() const {
  return message_as_ComponentReturn();
}

struct RootBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_message_type(Message message_type) {
    fbb_.AddElement<uint8_t>(Root::VT_MESSAGE_TYPE, static_cast<uint8_t>(message_type), 0);
  }
  void add_message(flatbuffers::Offset<void> message) {
    fbb_.AddOffset(Root::VT_MESSAGE, message);
  }
  explicit RootBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  RootBuilder &operator=(const RootBuilder &);
  flatbuffers::Offset<Root> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Root>(end);
    return o;
  }
};

inline flatbuffers::Offset<Root> CreateRoot(
    flatbuffers::FlatBufferBuilder &_fbb,
    Message message_type = Message_NONE,
    flatbuffers::Offset<void> message = 0) {
  RootBuilder builder_(_fbb);
  builder_.add_message(message);
  builder_.add_message_type(message_type);
  return builder_.Finish();
}

/// Concrete variable values.
/// Used for linear combinations and assignments.
struct VariableValues FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VARIABLE_IDS = 4,
    VT_ELEMENTS = 6
  };
  /// The IDs of the variables being assigned to.
  const flatbuffers::Vector<uint64_t> *variable_ids() const {
    return GetPointer<const flatbuffers::Vector<uint64_t> *>(VT_VARIABLE_IDS);
  }
  /// Field Elements assigned to variables.
  /// Contiguous BigInts in the same order as variable_ids.
  ///
  /// The field in use is defined in `instance.field_order`.
  ///
  /// The size of an element representation is determined by:
  ///     element size = elements.length / variable_ids.length
  ///
  /// The element representation may be truncated and therefore shorter
  /// than the canonical representation. Truncated bytes are treated as zeros.
  const flatbuffers::Vector<uint8_t> *elements() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_ELEMENTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_VARIABLE_IDS) &&
           verifier.VerifyVector(variable_ids()) &&
           VerifyOffset(verifier, VT_ELEMENTS) &&
           verifier.VerifyVector(elements()) &&
           verifier.EndTable();
  }
};

struct VariableValuesBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_variable_ids(flatbuffers::Offset<flatbuffers::Vector<uint64_t>> variable_ids) {
    fbb_.AddOffset(VariableValues::VT_VARIABLE_IDS, variable_ids);
  }
  void add_elements(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> elements) {
    fbb_.AddOffset(VariableValues::VT_ELEMENTS, elements);
  }
  explicit VariableValuesBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  VariableValuesBuilder &operator=(const VariableValuesBuilder &);
  flatbuffers::Offset<VariableValues> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<VariableValues>(end);
    return o;
  }
};

inline flatbuffers::Offset<VariableValues> CreateVariableValues(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<uint64_t>> variable_ids = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> elements = 0) {
  VariableValuesBuilder builder_(_fbb);
  builder_.add_elements(elements);
  builder_.add_variable_ids(variable_ids);
  return builder_.Finish();
}

inline flatbuffers::Offset<VariableValues> CreateVariableValuesDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint64_t> *variable_ids = nullptr,
    const std::vector<uint8_t> *elements = nullptr) {
  auto variable_ids__ = variable_ids ? _fbb.CreateVector<uint64_t>(*variable_ids) : 0;
  auto elements__ = elements ? _fbb.CreateVector<uint8_t>(*elements) : 0;
  return Gadget::CreateVariableValues(
      _fbb,
      variable_ids__,
      elements__);
}

/// An R1CS constraint between variables.
struct BilinearConstraint FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_LINEAR_COMBINATION_A = 4,
    VT_LINEAR_COMBINATION_B = 6,
    VT_LINEAR_COMBINATION_C = 8
  };
  const VariableValues *linear_combination_a() const {
    return GetPointer<const VariableValues *>(VT_LINEAR_COMBINATION_A);
  }
  const VariableValues *linear_combination_b() const {
    return GetPointer<const VariableValues *>(VT_LINEAR_COMBINATION_B);
  }
  const VariableValues *linear_combination_c() const {
    return GetPointer<const VariableValues *>(VT_LINEAR_COMBINATION_C);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_LINEAR_COMBINATION_A) &&
           verifier.VerifyTable(linear_combination_a()) &&
           VerifyOffset(verifier, VT_LINEAR_COMBINATION_B) &&
           verifier.VerifyTable(linear_combination_b()) &&
           VerifyOffset(verifier, VT_LINEAR_COMBINATION_C) &&
           verifier.VerifyTable(linear_combination_c()) &&
           verifier.EndTable();
  }
};

struct BilinearConstraintBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_linear_combination_a(flatbuffers::Offset<VariableValues> linear_combination_a) {
    fbb_.AddOffset(BilinearConstraint::VT_LINEAR_COMBINATION_A, linear_combination_a);
  }
  void add_linear_combination_b(flatbuffers::Offset<VariableValues> linear_combination_b) {
    fbb_.AddOffset(BilinearConstraint::VT_LINEAR_COMBINATION_B, linear_combination_b);
  }
  void add_linear_combination_c(flatbuffers::Offset<VariableValues> linear_combination_c) {
    fbb_.AddOffset(BilinearConstraint::VT_LINEAR_COMBINATION_C, linear_combination_c);
  }
  explicit BilinearConstraintBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  BilinearConstraintBuilder &operator=(const BilinearConstraintBuilder &);
  flatbuffers::Offset<BilinearConstraint> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<BilinearConstraint>(end);
    return o;
  }
};

inline flatbuffers::Offset<BilinearConstraint> CreateBilinearConstraint(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<VariableValues> linear_combination_a = 0,
    flatbuffers::Offset<VariableValues> linear_combination_b = 0,
    flatbuffers::Offset<VariableValues> linear_combination_c = 0) {
  BilinearConstraintBuilder builder_(_fbb);
  builder_.add_linear_combination_c(linear_combination_c);
  builder_.add_linear_combination_b(linear_combination_b);
  builder_.add_linear_combination_a(linear_combination_a);
  return builder_.Finish();
}

/// Description of a particular instance of a gadget.
struct GadgetInstance FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_GADGET_NAME = 4,
    VT_INCOMING_VARIABLE_IDS = 6,
    VT_OUTGOING_VARIABLE_IDS = 8,
    VT_FREE_VARIABLE_ID_BEFORE = 10,
    VT_FIELD_ORDER = 12,
    VT_CONFIGURATION = 14
  };
  /// Which gadget to instantiate.
  /// Allows a library to provide multiple gadgets.
  const flatbuffers::String *gadget_name() const {
    return GetPointer<const flatbuffers::String *>(VT_GADGET_NAME);
  }
  /// Incoming Variables to use as connections to the gadget.
  /// Allocated by the caller.
  /// Assigned by the caller in `Witness.incoming_elements`.
  const flatbuffers::Vector<uint64_t> *incoming_variable_ids() const {
    return GetPointer<const flatbuffers::Vector<uint64_t> *>(VT_INCOMING_VARIABLE_IDS);
  }
  /// Outgoing Variables to use as connections to the gadget.
  /// There may be no Outgoing Variables if the gadget is a pure assertion.
  /// Allocated by the caller.
  /// Assigned by the called gadget in `ComponentReturn.outgoing_elements`.
  const flatbuffers::Vector<uint64_t> *outgoing_variable_ids() const {
    return GetPointer<const flatbuffers::Vector<uint64_t> *>(VT_OUTGOING_VARIABLE_IDS);
  }
  /// First free Variable ID before the call.
  /// The gadget can allocate new Variable IDs starting with this one.
  uint64_t free_variable_id_before() const {
    return GetField<uint64_t>(VT_FREE_VARIABLE_ID_BEFORE, 0);
  }
  /// The order of the field used by the current system.
  /// A BigInt.
  const flatbuffers::Vector<uint8_t> *field_order() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_FIELD_ORDER);
  }
  /// Optional: Any static parameter that may influence the instance construction.
  /// Parameters can be standard, conventional, or specific to a gadget.
  /// Example: the depth of a Merkle tree.
  /// Counter-example: the Merkle authentication path is not configuration (rather witness).
  const flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>> *configuration() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>> *>(VT_CONFIGURATION);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_GADGET_NAME) &&
           verifier.VerifyString(gadget_name()) &&
           VerifyOffset(verifier, VT_INCOMING_VARIABLE_IDS) &&
           verifier.VerifyVector(incoming_variable_ids()) &&
           VerifyOffset(verifier, VT_OUTGOING_VARIABLE_IDS) &&
           verifier.VerifyVector(outgoing_variable_ids()) &&
           VerifyField<uint64_t>(verifier, VT_FREE_VARIABLE_ID_BEFORE) &&
           VerifyOffset(verifier, VT_FIELD_ORDER) &&
           verifier.VerifyVector(field_order()) &&
           VerifyOffset(verifier, VT_CONFIGURATION) &&
           verifier.VerifyVector(configuration()) &&
           verifier.VerifyVectorOfTables(configuration()) &&
           verifier.EndTable();
  }
};

struct GadgetInstanceBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_gadget_name(flatbuffers::Offset<flatbuffers::String> gadget_name) {
    fbb_.AddOffset(GadgetInstance::VT_GADGET_NAME, gadget_name);
  }
  void add_incoming_variable_ids(flatbuffers::Offset<flatbuffers::Vector<uint64_t>> incoming_variable_ids) {
    fbb_.AddOffset(GadgetInstance::VT_INCOMING_VARIABLE_IDS, incoming_variable_ids);
  }
  void add_outgoing_variable_ids(flatbuffers::Offset<flatbuffers::Vector<uint64_t>> outgoing_variable_ids) {
    fbb_.AddOffset(GadgetInstance::VT_OUTGOING_VARIABLE_IDS, outgoing_variable_ids);
  }
  void add_free_variable_id_before(uint64_t free_variable_id_before) {
    fbb_.AddElement<uint64_t>(GadgetInstance::VT_FREE_VARIABLE_ID_BEFORE, free_variable_id_before, 0);
  }
  void add_field_order(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> field_order) {
    fbb_.AddOffset(GadgetInstance::VT_FIELD_ORDER, field_order);
  }
  void add_configuration(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>>> configuration) {
    fbb_.AddOffset(GadgetInstance::VT_CONFIGURATION, configuration);
  }
  explicit GadgetInstanceBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GadgetInstanceBuilder &operator=(const GadgetInstanceBuilder &);
  flatbuffers::Offset<GadgetInstance> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GadgetInstance>(end);
    return o;
  }
};

inline flatbuffers::Offset<GadgetInstance> CreateGadgetInstance(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> gadget_name = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint64_t>> incoming_variable_ids = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint64_t>> outgoing_variable_ids = 0,
    uint64_t free_variable_id_before = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> field_order = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>>> configuration = 0) {
  GadgetInstanceBuilder builder_(_fbb);
  builder_.add_free_variable_id_before(free_variable_id_before);
  builder_.add_configuration(configuration);
  builder_.add_field_order(field_order);
  builder_.add_outgoing_variable_ids(outgoing_variable_ids);
  builder_.add_incoming_variable_ids(incoming_variable_ids);
  builder_.add_gadget_name(gadget_name);
  return builder_.Finish();
}

inline flatbuffers::Offset<GadgetInstance> CreateGadgetInstanceDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *gadget_name = nullptr,
    const std::vector<uint64_t> *incoming_variable_ids = nullptr,
    const std::vector<uint64_t> *outgoing_variable_ids = nullptr,
    uint64_t free_variable_id_before = 0,
    const std::vector<uint8_t> *field_order = nullptr,
    const std::vector<flatbuffers::Offset<CustomKeyValue>> *configuration = nullptr) {
  auto gadget_name__ = gadget_name ? _fbb.CreateString(gadget_name) : 0;
  auto incoming_variable_ids__ = incoming_variable_ids ? _fbb.CreateVector<uint64_t>(*incoming_variable_ids) : 0;
  auto outgoing_variable_ids__ = outgoing_variable_ids ? _fbb.CreateVector<uint64_t>(*outgoing_variable_ids) : 0;
  auto field_order__ = field_order ? _fbb.CreateVector<uint8_t>(*field_order) : 0;
  auto configuration__ = configuration ? _fbb.CreateVector<flatbuffers::Offset<CustomKeyValue>>(*configuration) : 0;
  return Gadget::CreateGadgetInstance(
      _fbb,
      gadget_name__,
      incoming_variable_ids__,
      outgoing_variable_ids__,
      free_variable_id_before,
      field_order__,
      configuration__);
}

/// Generic key-value for custom attributes.
struct CustomKeyValue FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_KEY = 4,
    VT_VALUE = 6
  };
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  const flatbuffers::Vector<uint8_t> *value() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_KEY) &&
           verifier.VerifyString(key()) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyVector(value()) &&
           verifier.EndTable();
  }
};

struct CustomKeyValueBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(CustomKeyValue::VT_KEY, key);
  }
  void add_value(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> value) {
    fbb_.AddOffset(CustomKeyValue::VT_VALUE, value);
  }
  explicit CustomKeyValueBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  CustomKeyValueBuilder &operator=(const CustomKeyValueBuilder &);
  flatbuffers::Offset<CustomKeyValue> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<CustomKeyValue>(end);
    return o;
  }
};

inline flatbuffers::Offset<CustomKeyValue> CreateCustomKeyValue(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> value = 0) {
  CustomKeyValueBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_key(key);
  return builder_.Finish();
}

inline flatbuffers::Offset<CustomKeyValue> CreateCustomKeyValueDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    const std::vector<uint8_t> *value = nullptr) {
  auto key__ = key ? _fbb.CreateString(key) : 0;
  auto value__ = value ? _fbb.CreateVector<uint8_t>(*value) : 0;
  return Gadget::CreateCustomKeyValue(
      _fbb,
      key__,
      value__);
}

/// Report constraints to be added to the constraints system.
/// To send to the stream of constraints.
struct R1CSConstraints FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_CONSTRAINTS = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<BilinearConstraint>> *constraints() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<BilinearConstraint>> *>(VT_CONSTRAINTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CONSTRAINTS) &&
           verifier.VerifyVector(constraints()) &&
           verifier.VerifyVectorOfTables(constraints()) &&
           verifier.EndTable();
  }
};

struct R1CSConstraintsBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_constraints(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<BilinearConstraint>>> constraints) {
    fbb_.AddOffset(R1CSConstraints::VT_CONSTRAINTS, constraints);
  }
  explicit R1CSConstraintsBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  R1CSConstraintsBuilder &operator=(const R1CSConstraintsBuilder &);
  flatbuffers::Offset<R1CSConstraints> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<R1CSConstraints>(end);
    return o;
  }
};

inline flatbuffers::Offset<R1CSConstraints> CreateR1CSConstraints(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<BilinearConstraint>>> constraints = 0) {
  R1CSConstraintsBuilder builder_(_fbb);
  builder_.add_constraints(constraints);
  return builder_.Finish();
}

inline flatbuffers::Offset<R1CSConstraints> CreateR1CSConstraintsDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<BilinearConstraint>> *constraints = nullptr) {
  auto constraints__ = constraints ? _fbb.CreateVector<flatbuffers::Offset<BilinearConstraint>>(*constraints) : 0;
  return Gadget::CreateR1CSConstraints(
      _fbb,
      constraints__);
}

/// Report local assignments computed by the gadget.
/// To send to the stream of assigned variables.
/// Does not include input and output variables.
struct AssignedVariables FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VALUES = 4
  };
  const VariableValues *values() const {
    return GetPointer<const VariableValues *>(VT_VALUES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_VALUES) &&
           verifier.VerifyTable(values()) &&
           verifier.EndTable();
  }
};

struct AssignedVariablesBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_values(flatbuffers::Offset<VariableValues> values) {
    fbb_.AddOffset(AssignedVariables::VT_VALUES, values);
  }
  explicit AssignedVariablesBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  AssignedVariablesBuilder &operator=(const AssignedVariablesBuilder &);
  flatbuffers::Offset<AssignedVariables> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<AssignedVariables>(end);
    return o;
  }
};

inline flatbuffers::Offset<AssignedVariables> CreateAssignedVariables(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<VariableValues> values = 0) {
  AssignedVariablesBuilder builder_(_fbb);
  builder_.add_values(values);
  return builder_.Finish();
}

struct ComponentCall FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_INSTANCE = 4,
    VT_GENERATE_R1CS = 6,
    VT_GENERATE_ASSIGNMENT = 8,
    VT_WITNESS = 10
  };
  /// All details necessary to construct the instance.
  /// The same instance must be provided for R1CS and assignment generation.
  const GadgetInstance *instance() const {
    return GetPointer<const GadgetInstance *>(VT_INSTANCE);
  }
  /// Whether constraints should be generated.
  bool generate_r1cs() const {
    return GetField<uint8_t>(VT_GENERATE_R1CS, 0) != 0;
  }
  /// Whether an assignment should be generated.
  /// Provide witness values to the component.
  bool generate_assignment() const {
    return GetField<uint8_t>(VT_GENERATE_ASSIGNMENT, 0) != 0;
  }
  const Witness *witness() const {
    return GetPointer<const Witness *>(VT_WITNESS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_INSTANCE) &&
           verifier.VerifyTable(instance()) &&
           VerifyField<uint8_t>(verifier, VT_GENERATE_R1CS) &&
           VerifyField<uint8_t>(verifier, VT_GENERATE_ASSIGNMENT) &&
           VerifyOffset(verifier, VT_WITNESS) &&
           verifier.VerifyTable(witness()) &&
           verifier.EndTable();
  }
};

struct ComponentCallBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_instance(flatbuffers::Offset<GadgetInstance> instance) {
    fbb_.AddOffset(ComponentCall::VT_INSTANCE, instance);
  }
  void add_generate_r1cs(bool generate_r1cs) {
    fbb_.AddElement<uint8_t>(ComponentCall::VT_GENERATE_R1CS, static_cast<uint8_t>(generate_r1cs), 0);
  }
  void add_generate_assignment(bool generate_assignment) {
    fbb_.AddElement<uint8_t>(ComponentCall::VT_GENERATE_ASSIGNMENT, static_cast<uint8_t>(generate_assignment), 0);
  }
  void add_witness(flatbuffers::Offset<Witness> witness) {
    fbb_.AddOffset(ComponentCall::VT_WITNESS, witness);
  }
  explicit ComponentCallBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ComponentCallBuilder &operator=(const ComponentCallBuilder &);
  flatbuffers::Offset<ComponentCall> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ComponentCall>(end);
    return o;
  }
};

inline flatbuffers::Offset<ComponentCall> CreateComponentCall(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<GadgetInstance> instance = 0,
    bool generate_r1cs = false,
    bool generate_assignment = false,
    flatbuffers::Offset<Witness> witness = 0) {
  ComponentCallBuilder builder_(_fbb);
  builder_.add_witness(witness);
  builder_.add_instance(instance);
  builder_.add_generate_assignment(generate_assignment);
  builder_.add_generate_r1cs(generate_r1cs);
  return builder_.Finish();
}

/// Details necessary to compute an assignment.
struct Witness FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_INCOMING_ELEMENTS = 4,
    VT_INFO = 6
  };
  /// The values that the caller assigned to Incoming Variables.
  /// Contiguous BigInts in the same order as `instance.incoming_variable_ids`.
  const flatbuffers::Vector<uint8_t> *incoming_elements() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_INCOMING_ELEMENTS);
  }
  /// Optional: Any info that may be useful to the gadget to compute its assignments.
  /// Example: Merkle authentication path.
  const flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>> *info() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>> *>(VT_INFO);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_INCOMING_ELEMENTS) &&
           verifier.VerifyVector(incoming_elements()) &&
           VerifyOffset(verifier, VT_INFO) &&
           verifier.VerifyVector(info()) &&
           verifier.VerifyVectorOfTables(info()) &&
           verifier.EndTable();
  }
};

struct WitnessBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_incoming_elements(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> incoming_elements) {
    fbb_.AddOffset(Witness::VT_INCOMING_ELEMENTS, incoming_elements);
  }
  void add_info(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>>> info) {
    fbb_.AddOffset(Witness::VT_INFO, info);
  }
  explicit WitnessBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  WitnessBuilder &operator=(const WitnessBuilder &);
  flatbuffers::Offset<Witness> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<Witness>(end);
    return o;
  }
};

inline flatbuffers::Offset<Witness> CreateWitness(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> incoming_elements = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>>> info = 0) {
  WitnessBuilder builder_(_fbb);
  builder_.add_info(info);
  builder_.add_incoming_elements(incoming_elements);
  return builder_.Finish();
}

inline flatbuffers::Offset<Witness> CreateWitnessDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint8_t> *incoming_elements = nullptr,
    const std::vector<flatbuffers::Offset<CustomKeyValue>> *info = nullptr) {
  auto incoming_elements__ = incoming_elements ? _fbb.CreateVector<uint8_t>(*incoming_elements) : 0;
  auto info__ = info ? _fbb.CreateVector<flatbuffers::Offset<CustomKeyValue>>(*info) : 0;
  return Gadget::CreateWitness(
      _fbb,
      incoming_elements__,
      info__);
}

/// Response after all R1CSConstraints or AssignedVariables have been sent.
struct ComponentReturn FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_FREE_VARIABLE_ID_AFTER = 4,
    VT_INFO = 6,
    VT_ERROR = 8,
    VT_OUTGOING_ELEMENTS = 10
  };
  /// First variable ID free after the gadget call.
  /// A variable ID greater than all IDs allocated by the gadget.
  uint64_t free_variable_id_after() const {
    return GetField<uint64_t>(VT_FREE_VARIABLE_ID_AFTER, 0);
  }
  /// Optional: Any info that may be useful to the caller.
  const flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>> *info() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>> *>(VT_INFO);
  }
  /// Optional: An error message. Null if no error.
  const flatbuffers::String *error() const {
    return GetPointer<const flatbuffers::String *>(VT_ERROR);
  }
  /// The values that the gadget assigned to outgoing variables, if any.
  /// Contiguous BigInts in the same order as `instance.outgoing_variable_ids`.
  const flatbuffers::Vector<uint8_t> *outgoing_elements() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_OUTGOING_ELEMENTS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_FREE_VARIABLE_ID_AFTER) &&
           VerifyOffset(verifier, VT_INFO) &&
           verifier.VerifyVector(info()) &&
           verifier.VerifyVectorOfTables(info()) &&
           VerifyOffset(verifier, VT_ERROR) &&
           verifier.VerifyString(error()) &&
           VerifyOffset(verifier, VT_OUTGOING_ELEMENTS) &&
           verifier.VerifyVector(outgoing_elements()) &&
           verifier.EndTable();
  }
};

struct ComponentReturnBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_free_variable_id_after(uint64_t free_variable_id_after) {
    fbb_.AddElement<uint64_t>(ComponentReturn::VT_FREE_VARIABLE_ID_AFTER, free_variable_id_after, 0);
  }
  void add_info(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>>> info) {
    fbb_.AddOffset(ComponentReturn::VT_INFO, info);
  }
  void add_error(flatbuffers::Offset<flatbuffers::String> error) {
    fbb_.AddOffset(ComponentReturn::VT_ERROR, error);
  }
  void add_outgoing_elements(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> outgoing_elements) {
    fbb_.AddOffset(ComponentReturn::VT_OUTGOING_ELEMENTS, outgoing_elements);
  }
  explicit ComponentReturnBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ComponentReturnBuilder &operator=(const ComponentReturnBuilder &);
  flatbuffers::Offset<ComponentReturn> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ComponentReturn>(end);
    return o;
  }
};

inline flatbuffers::Offset<ComponentReturn> CreateComponentReturn(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t free_variable_id_after = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<CustomKeyValue>>> info = 0,
    flatbuffers::Offset<flatbuffers::String> error = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> outgoing_elements = 0) {
  ComponentReturnBuilder builder_(_fbb);
  builder_.add_free_variable_id_after(free_variable_id_after);
  builder_.add_outgoing_elements(outgoing_elements);
  builder_.add_error(error);
  builder_.add_info(info);
  return builder_.Finish();
}

inline flatbuffers::Offset<ComponentReturn> CreateComponentReturnDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t free_variable_id_after = 0,
    const std::vector<flatbuffers::Offset<CustomKeyValue>> *info = nullptr,
    const char *error = nullptr,
    const std::vector<uint8_t> *outgoing_elements = nullptr) {
  auto info__ = info ? _fbb.CreateVector<flatbuffers::Offset<CustomKeyValue>>(*info) : 0;
  auto error__ = error ? _fbb.CreateString(error) : 0;
  auto outgoing_elements__ = outgoing_elements ? _fbb.CreateVector<uint8_t>(*outgoing_elements) : 0;
  return Gadget::CreateComponentReturn(
      _fbb,
      free_variable_id_after,
      info__,
      error__,
      outgoing_elements__);
}

inline bool VerifyMessage(flatbuffers::Verifier &verifier, const void *obj, Message type) {
  switch (type) {
    case Message_NONE: {
      return true;
    }
    case Message_R1CSConstraints: {
      auto ptr = reinterpret_cast<const R1CSConstraints *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_AssignedVariables: {
      auto ptr = reinterpret_cast<const AssignedVariables *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_ComponentCall: {
      auto ptr = reinterpret_cast<const ComponentCall *>(obj);
      return verifier.VerifyTable(ptr);
    }
    case Message_ComponentReturn: {
      auto ptr = reinterpret_cast<const ComponentReturn *>(obj);
      return verifier.VerifyTable(ptr);
    }
    default: return false;
  }
}

inline bool VerifyMessageVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyMessage(
        verifier,  values->Get(i), types->GetEnum<Message>(i))) {
      return false;
    }
  }
  return true;
}

inline const Gadget::Root *GetRoot(const void *buf) {
  return flatbuffers::GetRoot<Gadget::Root>(buf);
}

inline const Gadget::Root *GetSizePrefixedRoot(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<Gadget::Root>(buf);
}

inline const char *RootIdentifier() {
  return "zkp2";
}

inline bool RootBufferHasIdentifier(const void *buf) {
  return flatbuffers::BufferHasIdentifier(
      buf, RootIdentifier());
}

inline bool VerifyRootBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<Gadget::Root>(RootIdentifier());
}

inline bool VerifySizePrefixedRootBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<Gadget::Root>(RootIdentifier());
}

inline const char *RootExtension() {
  return "zkp2";
}

inline void FinishRootBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Gadget::Root> root) {
  fbb.Finish(root, RootIdentifier());
}

inline void FinishSizePrefixedRootBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<Gadget::Root> root) {
  fbb.FinishSizePrefixed(root, RootIdentifier());
}

}  // namespace Gadget

#endif  // FLATBUFFERS_GENERATED_GADGET_GADGET_H_
