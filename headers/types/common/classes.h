#ifndef HEADERS_TYPES_COMMON_CLASSES_H_
#define HEADERS_TYPES_COMMON_CLASSES_H_

struct __class_type_info {
    void* metaclass_vftable; // Pointer to the vftable for __cxxabiv1::__class_type_info
    char* name;              // Mangled name; all demangled names are available in the symbol files
};

ASSERT_SIZE(struct __class_type_info, 8);

struct __si_class_type_info {
    void* metaclass_vftable; // Pointer to the vftable for __cxxabiv1::__si_class_type_info
    char* name;              // Mangled name; all demangled names are available in the symbol files
    union class_type_info*
        base_class; // Can be a __class_type_info, OR another __si_class_type_info.
};

ASSERT_SIZE(struct __si_class_type_info, 12);

union class_type_info {
    struct __class_type_info base;
    struct __si_class_type_info inherited;
};

ASSERT_SIZE(union class_type_info, 12);

#endif
