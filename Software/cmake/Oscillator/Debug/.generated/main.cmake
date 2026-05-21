include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Oscillator_Debug_library_list )

# Handle files with suffix s, for group Debug-avr-gcc
if(Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_assemble)
add_library(Oscillator_Debug_Debug_avr_gcc_assemble OBJECT ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_assemble})
    Oscillator_Debug_Debug_avr_gcc_assemble_rule(Oscillator_Debug_Debug_avr_gcc_assemble)
    list(APPEND Oscillator_Debug_library_list "$<TARGET_OBJECTS:Oscillator_Debug_Debug_avr_gcc_assemble>")

endif()

# Handle files with suffix S, for group Debug-avr-gcc
if(Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_assembleWithPreprocess)
add_library(Oscillator_Debug_Debug_avr_gcc_assembleWithPreprocess OBJECT ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_assembleWithPreprocess})
    Oscillator_Debug_Debug_avr_gcc_assembleWithPreprocess_rule(Oscillator_Debug_Debug_avr_gcc_assembleWithPreprocess)
    list(APPEND Oscillator_Debug_library_list "$<TARGET_OBJECTS:Oscillator_Debug_Debug_avr_gcc_assembleWithPreprocess>")

endif()

# Handle files with suffix [cC], for group Debug-avr-gcc
if(Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_compile)
add_library(Oscillator_Debug_Debug_avr_gcc_compile OBJECT ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_compile})
    Oscillator_Debug_Debug_avr_gcc_compile_rule(Oscillator_Debug_Debug_avr_gcc_compile)
    list(APPEND Oscillator_Debug_library_list "$<TARGET_OBJECTS:Oscillator_Debug_Debug_avr_gcc_compile>")

endif()

# Handle files with suffix cpp, for group Debug-avr-gcc
if(Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_compile_cpp)
add_library(Oscillator_Debug_Debug_avr_gcc_compile_cpp OBJECT ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_compile_cpp})
    Oscillator_Debug_Debug_avr_gcc_compile_cpp_rule(Oscillator_Debug_Debug_avr_gcc_compile_cpp)
    list(APPEND Oscillator_Debug_library_list "$<TARGET_OBJECTS:Oscillator_Debug_Debug_avr_gcc_compile_cpp>")

endif()

# Handle files with suffix elf, for group Debug-avr-gcc
if(Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_ihex)
add_library(Oscillator_Debug_Debug_avr_gcc_objcopy_ihex OBJECT ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_ihex})
    Oscillator_Debug_Debug_avr_gcc_objcopy_ihex_rule(Oscillator_Debug_Debug_avr_gcc_objcopy_ihex)
    list(APPEND Oscillator_Debug_library_list "$<TARGET_OBJECTS:Oscillator_Debug_Debug_avr_gcc_objcopy_ihex>")

endif()

# Handle files with suffix elf, for group Debug-avr-gcc
if(Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_eep)
add_library(Oscillator_Debug_Debug_avr_gcc_objcopy_eep OBJECT ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_eep})
    Oscillator_Debug_Debug_avr_gcc_objcopy_eep_rule(Oscillator_Debug_Debug_avr_gcc_objcopy_eep)
    list(APPEND Oscillator_Debug_library_list "$<TARGET_OBJECTS:Oscillator_Debug_Debug_avr_gcc_objcopy_eep>")

endif()

# Handle files with suffix elf, for group Debug-avr-gcc
if(Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_lss)
add_library(Oscillator_Debug_Debug_avr_gcc_objcopy_lss OBJECT ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_lss})
    Oscillator_Debug_Debug_avr_gcc_objcopy_lss_rule(Oscillator_Debug_Debug_avr_gcc_objcopy_lss)
    list(APPEND Oscillator_Debug_library_list "$<TARGET_OBJECTS:Oscillator_Debug_Debug_avr_gcc_objcopy_lss>")

endif()

# Handle files with suffix elf, for group Debug-avr-gcc
if(Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_srec)
add_library(Oscillator_Debug_Debug_avr_gcc_objcopy_srec OBJECT ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_srec})
    Oscillator_Debug_Debug_avr_gcc_objcopy_srec_rule(Oscillator_Debug_Debug_avr_gcc_objcopy_srec)
    list(APPEND Oscillator_Debug_library_list "$<TARGET_OBJECTS:Oscillator_Debug_Debug_avr_gcc_objcopy_srec>")

endif()

# Handle files with suffix elf, for group Debug-avr-gcc
if(Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_sig)
add_library(Oscillator_Debug_Debug_avr_gcc_objcopy_sig OBJECT ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_objcopy_sig})
    Oscillator_Debug_Debug_avr_gcc_objcopy_sig_rule(Oscillator_Debug_Debug_avr_gcc_objcopy_sig)
    list(APPEND Oscillator_Debug_library_list "$<TARGET_OBJECTS:Oscillator_Debug_Debug_avr_gcc_objcopy_sig>")

endif()


# Main target for this project
add_executable(Oscillator_Debug_image_CdJaN_UP ${Oscillator_Debug_library_list})

set_target_properties(Oscillator_Debug_image_CdJaN_UP PROPERTIES
    OUTPUT_NAME "Debug"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${Oscillator_Debug_output_dir}")
target_link_libraries(Oscillator_Debug_image_CdJaN_UP PRIVATE ${Oscillator_Debug_Debug_avr_gcc_FILE_TYPE_link})

#Add objcopy steps
Oscillator_Debug_objcopy_ihex_rule(Oscillator_Debug_image_CdJaN_UP)
Oscillator_Debug_objcopy_eep_rule(Oscillator_Debug_image_CdJaN_UP)
Oscillator_Debug_objcopy_lss_rule(Oscillator_Debug_image_CdJaN_UP)
Oscillator_Debug_objcopy_srec_rule(Oscillator_Debug_image_CdJaN_UP)
Oscillator_Debug_objcopy_sig_rule(Oscillator_Debug_image_CdJaN_UP)
# Add the link options from the rule file.
Oscillator_Debug_link_rule( Oscillator_Debug_image_CdJaN_UP)


