set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")

set(SPEED_ALGORITHM_SOURCE_FILES
        speed/algorithm/algorithm.hpp
        speed/algorithm.hpp
        )

set(SPEED_ARGPARSE_SOURCE_FILES
        speed/argparse/arg_error_flags.hpp
        speed/argparse/arg_flags.hpp
        speed/argparse/arg_parser_error_flags.hpp
        speed/argparse/arg_parser_flags.hpp
        speed/argparse/arg_value_error_flags.hpp
        speed/argparse/arg_value_types.hpp
        speed/argparse/argparse_exception.hpp
        speed/argparse/argparse_forward_declarations.hpp
        speed/argparse/basic_arg_key.hpp
        speed/argparse/basic_arg_parser.hpp
        speed/argparse/basic_arg_value.hpp
        speed/argparse/basic_base_arg.hpp
        speed/argparse/basic_keyless_arg.hpp
        speed/argparse/basic_help_arg.hpp
        speed/argparse/basic_help_text.hpp
        speed/argparse/basic_key_arg.hpp
        speed/argparse/basic_key_value_arg.hpp
        speed/argparse/basic_relational_constraint.hpp
        speed/argparse/basic_value_arg.hpp
        speed/argparse/basic_version_arg.hpp
        speed/argparse/i_help_text.hpp
        speed/argparse/relational_constraint_types.hpp
        speed/argparse.hpp
        )

set(SPEED_CONTAINERS_SOURCE_FILES
        speed/containers/circular_doubly_linked_list.hpp
        speed/containers/containers_exception.hpp
        speed/containers/doubly_linked_node.hpp
        speed/containers/flags.hpp
        speed/containers/i_const_iterator.hpp
        speed/containers/i_const_mutable_iterator.hpp
        speed/containers/i_iterator.hpp
        speed/containers/i_mutable_iterator.hpp
        speed/containers/static_cache.hpp
        speed/containers.hpp
        )

set(SPEED_EXCEPTION_SOURCE_FILES
        speed/exception/exception_base.hpp
        speed/exception/message_exception_base.hpp
        speed/exception.hpp
        )

set(SPEED_FILESYSTEM_SOURCE_FILES
        speed/filesystem/directory_iteration.cpp
        speed/filesystem/directory_iteration.hpp
        speed/filesystem.hpp
        )

set(SPEED_IOSTREAM_SOURCE_FILES
        speed/iostream/indentation.cpp
        speed/iostream/indentation.hpp
        speed/iostream/basic_ios_redirect.hpp
        speed/iostream/basic_ostream.hpp
        speed/iostream/stdio.cpp
        speed/iostream/stdio.hpp
        speed/iostream.hpp
        )

set(SPEED_LOWLEVEL_SOURCE_FILES
        speed/lowlevel/arithmetic_operations.hpp
        speed/lowlevel/enum_bitwise_operators.hpp
        speed/lowlevel/logical_operations.hpp
        speed/lowlevel/lowlevel_exception.hpp
        speed/lowlevel.hpp
        )

set(SPEED_MATH_SOURCE_FILES
        speed/math/math.hpp
        speed/math.hpp
        )

set(SPEED_SCALARS_SOURCE_FILES
        speed/scalars/scalar.hpp
        speed/scalars/scalars.hpp
        speed/scalars.hpp
        )

set(SPEED_STRINGUTILS_SOURCE_FILES
        speed/stringutils/c_string_utils.hpp
        speed/stringutils/string_utils.hpp
        speed/stringutils.hpp
        )

set(SPEED_SYSTEM_SOURCE_FILES
        speed/system/api/glibc/filesystem.cpp
        speed/system/api/glibc/filesystem.hpp
        speed/system/api/glibc/process.cpp
        speed/system/api/glibc/process.hpp
        speed/system/api/glibc/terminal.cpp
        speed/system/api/glibc/terminal.hpp
        speed/system/api/glibc/time.cpp
        speed/system/api/glibc/time.hpp
        speed/system/types.hpp
        speed/system/error_code.hpp
        speed/system/filesystem/access_modes.hpp
        speed/system/filesystem/file_types.hpp
        speed/system/filesystem/filesystem.hpp
        speed/system/process/process.hpp
        speed/system/system_exception.hpp
        speed/system/system_macros.hpp
        speed/system/terminal/terminal.hpp
        speed/system/terminal/text_attribute.hpp
        speed/system/time/time.cpp
        speed/system/time/time.hpp
        speed/system.hpp
        )

set(SPEED_TIME_SOURCE_FILES
        speed/time/child_cpu_chrono.cpp
        speed/time/child_cpu_chrono.hpp
        speed/time/chrono_states.hpp
        speed/time/cpu_chrono.cpp
        speed/time/cpu_chrono.hpp
        speed/time/i_chrono.hpp
        speed/time/monotonic_chrono.cpp
        speed/time/monotonic_chrono.hpp
        speed/time/monotonic_timer.cpp
        speed/time/monotonic_timer.hpp
        speed/time.hpp
        )

set(SPEED_TYPE_CASTING_SOURCE_FILES
        speed/type_casting/basic_string_to_type.hpp
        speed/type_casting/c_string_to_basic_string.hpp
        speed/type_casting/c_string_to_floating_point.hpp
        speed/type_casting/c_string_to_integral_signed.hpp
        speed/type_casting/c_string_to_integral_unsigned.hpp
        speed/type_casting/c_string_to_path.hpp
        speed/type_casting/type_cast.hpp
        speed/type_casting/type_casting_exception.hpp
        speed/type_casting.hpp
        )

set(SPEED_TYPE_TRAITS_SOURCE_FILES
        speed/type_traits/type_traits.hpp
        speed/type_traits.hpp
        )

set(SPEED_SOURCE_FILES
        ${SPEED_ALGORITHM_SOURCE_FILES}
        ${SPEED_ARGPARSE_SOURCE_FILES}
        ${SPEED_CONTAINERS_SOURCE_FILES}
        ${SPEED_EXCEPTION_SOURCE_FILES}
        ${SPEED_FILESYSTEM_SOURCE_FILES}
        ${SPEED_IOSTREAM_SOURCE_FILES}
        ${SPEED_LOWLEVEL_SOURCE_FILES}
        ${SPEED_MATH_SOURCE_FILES}
        ${SPEED_SCALARS_SOURCE_FILES}
        ${SPEED_STRINGUTILS_SOURCE_FILES}
        ${SPEED_SYSTEM_SOURCE_FILES}
        ${SPEED_TIME_SOURCE_FILES}
        ${SPEED_TYPE_CASTING_SOURCE_FILES}
        ${SPEED_TYPE_TRAITS_SOURCE_FILES}
        speed/speed.hpp
        speed/speed_alias.hpp
        speed/speed_version.hpp
        )

add_library(speed_algorithm STATIC ${SPEED_ALGORITHM_SOURCE_FILES})
add_library(speed_argparse STATIC ${SPEED_ARGPARSE_SOURCE_FILES})
add_library(speed_containers STATIC ${SPEED_CONTAINERS_SOURCE_FILES})
add_library(speed_exception STATIC ${SPEED_EXCEPTION_SOURCE_FILES})
add_library(speed_filesystem STATIC ${SPEED_FILESYSTEM_SOURCE_FILES})
add_library(speed_iostream STATIC ${SPEED_IOSTREAM_SOURCE_FILES})
add_library(speed_lowlevel STATIC ${SPEED_LOWLEVEL_SOURCE_FILES})
add_library(speed_math STATIC ${SPEED_MATH_SOURCE_FILES})
add_library(speed_scalars STATIC ${SPEED_SCALARS_SOURCE_FILES})
add_library(speed_stringutils STATIC ${SPEED_STRINGUTILS_SOURCE_FILES})
add_library(speed_system STATIC ${SPEED_SYSTEM_SOURCE_FILES})
add_library(speed_time STATIC ${SPEED_TIME_SOURCE_FILES})
add_library(speed_type_casting STATIC ${SPEED_TYPE_CASTING_SOURCE_FILES})
add_library(speed_type_traits STATIC ${SPEED_TYPE_TRAITS_SOURCE_FILES})
add_library(speed STATIC ${SPEED_SOURCE_FILES})

target_link_libraries(speed_argparse speed_containers speed_exception speed_lowlevel 
                      speed_stringutils speed_system speed_type_casting -lstdc++fs)
target_link_libraries(speed_containers speed_exception speed_iostream speed_type_traits)
target_link_libraries(speed_filesystem speed_containers speed_system)
target_link_libraries(speed_iostream speed_system)
target_link_libraries(speed_lowlevel speed_exception speed_type_traits)
target_link_libraries(speed_stringutils speed_type_traits)
target_link_libraries(speed_system speed_exception speed_lowlevel -lstdc++fs)
target_link_libraries(speed_time speed_system)
target_link_libraries(speed_type_casting speed_exception speed_stringutils speed_type_traits 
                      -lstdc++fs)
target_link_libraries(speed_type_traits -lstdc++fs)
target_link_libraries(speed
        speed_algorithm
        speed_argparse
        speed_containers
        speed_exception
        speed_filesystem
        speed_iostream
        speed_lowlevel
        speed_math
        speed_scalars
        speed_stringutils
        speed_system
        speed_time
        speed_type_casting
        speed_type_traits
        )

set_target_properties(speed_algorithm PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_argparse PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_containers PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_exception PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_filesystem PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_iostream PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_lowlevel PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_math PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_scalars PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_stringutils PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_system PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_time PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_type_casting PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed_type_traits PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(speed PROPERTIES LINKER_LANGUAGE CXX)

install(TARGETS speed_algorithm DESTINATION lib)
install(TARGETS speed_argparse DESTINATION lib)
install(TARGETS speed_containers DESTINATION lib)
install(TARGETS speed_exception DESTINATION lib)
install(TARGETS speed_filesystem DESTINATION lib)
install(TARGETS speed_iostream DESTINATION lib)
install(TARGETS speed_lowlevel DESTINATION lib)
install(TARGETS speed_math DESTINATION lib)
install(TARGETS speed_scalars DESTINATION lib)
install(TARGETS speed_stringutils DESTINATION lib)
install(TARGETS speed_system DESTINATION lib)
install(TARGETS speed_time DESTINATION lib)
install(TARGETS speed_type_casting DESTINATION lib)
install(TARGETS speed_type_traits DESTINATION lib)
install(TARGETS speed DESTINATION lib)

install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/speed
        DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}/../include
        USE_SOURCE_PERMISSIONS
        FILES_MATCHING PATTERN "*.hpp")
install(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/../include/speed
        DESTINATION include)
