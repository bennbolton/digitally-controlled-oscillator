include("${CMAKE_CURRENT_LIST_DIR}/rule.cmake")
include("${CMAKE_CURRENT_LIST_DIR}/file.cmake")

set(Oscillator_Release_library_list )

# Handle files with suffix s, for group Release-avr-gcc
if(Oscillator_Release_Release_avr_gcc_FILE_TYPE_assemble)
add_library(Oscillator_Release_Release_avr_gcc_assemble OBJECT ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_assemble})
    Oscillator_Release_Release_avr_gcc_assemble_rule(Oscillator_Release_Release_avr_gcc_assemble)
    list(APPEND Oscillator_Release_library_list "$<TARGET_OBJECTS:Oscillator_Release_Release_avr_gcc_assemble>")

endif()

# Handle files with suffix S, for group Release-avr-gcc
if(Oscillator_Release_Release_avr_gcc_FILE_TYPE_assembleWithPreprocess)
add_library(Oscillator_Release_Release_avr_gcc_assembleWithPreprocess OBJECT ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_assembleWithPreprocess})
    Oscillator_Release_Release_avr_gcc_assembleWithPreprocess_rule(Oscillator_Release_Release_avr_gcc_assembleWithPreprocess)
    list(APPEND Oscillator_Release_library_list "$<TARGET_OBJECTS:Oscillator_Release_Release_avr_gcc_assembleWithPreprocess>")

endif()

# Handle files with suffix [cC], for group Release-avr-gcc
if(Oscillator_Release_Release_avr_gcc_FILE_TYPE_compile)
add_library(Oscillator_Release_Release_avr_gcc_compile OBJECT ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_compile})
    Oscillator_Release_Release_avr_gcc_compile_rule(Oscillator_Release_Release_avr_gcc_compile)
    list(APPEND Oscillator_Release_library_list "$<TARGET_OBJECTS:Oscillator_Release_Release_avr_gcc_compile>")

endif()

# Handle files with suffix cpp, for group Release-avr-gcc
if(Oscillator_Release_Release_avr_gcc_FILE_TYPE_compile_cpp)
add_library(Oscillator_Release_Release_avr_gcc_compile_cpp OBJECT ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_compile_cpp})
    Oscillator_Release_Release_avr_gcc_compile_cpp_rule(Oscillator_Release_Release_avr_gcc_compile_cpp)
    list(APPEND Oscillator_Release_library_list "$<TARGET_OBJECTS:Oscillator_Release_Release_avr_gcc_compile_cpp>")

endif()

# Handle files with suffix elf, for group Release-avr-gcc
if(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_ihex)
add_library(Oscillator_Release_Release_avr_gcc_objcopy_ihex OBJECT ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_ihex})
    Oscillator_Release_Release_avr_gcc_objcopy_ihex_rule(Oscillator_Release_Release_avr_gcc_objcopy_ihex)
    list(APPEND Oscillator_Release_library_list "$<TARGET_OBJECTS:Oscillator_Release_Release_avr_gcc_objcopy_ihex>")

endif()

# Handle files with suffix elf, for group Release-avr-gcc
if(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_eep)
add_library(Oscillator_Release_Release_avr_gcc_objcopy_eep OBJECT ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_eep})
    Oscillator_Release_Release_avr_gcc_objcopy_eep_rule(Oscillator_Release_Release_avr_gcc_objcopy_eep)
    list(APPEND Oscillator_Release_library_list "$<TARGET_OBJECTS:Oscillator_Release_Release_avr_gcc_objcopy_eep>")

endif()

# Handle files with suffix elf, for group Release-avr-gcc
if(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_lss)
add_library(Oscillator_Release_Release_avr_gcc_objcopy_lss OBJECT ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_lss})
    Oscillator_Release_Release_avr_gcc_objcopy_lss_rule(Oscillator_Release_Release_avr_gcc_objcopy_lss)
    list(APPEND Oscillator_Release_library_list "$<TARGET_OBJECTS:Oscillator_Release_Release_avr_gcc_objcopy_lss>")

endif()

# Handle files with suffix elf, for group Release-avr-gcc
if(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_srec)
add_library(Oscillator_Release_Release_avr_gcc_objcopy_srec OBJECT ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_srec})
    Oscillator_Release_Release_avr_gcc_objcopy_srec_rule(Oscillator_Release_Release_avr_gcc_objcopy_srec)
    list(APPEND Oscillator_Release_library_list "$<TARGET_OBJECTS:Oscillator_Release_Release_avr_gcc_objcopy_srec>")

endif()

# Handle files with suffix elf, for group Release-avr-gcc
if(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_sig)
add_library(Oscillator_Release_Release_avr_gcc_objcopy_sig OBJECT ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_sig})
    Oscillator_Release_Release_avr_gcc_objcopy_sig_rule(Oscillator_Release_Release_avr_gcc_objcopy_sig)
    list(APPEND Oscillator_Release_library_list "$<TARGET_OBJECTS:Oscillator_Release_Release_avr_gcc_objcopy_sig>")

endif()


# Main target for this project
add_executable(Oscillator_Release_image_gPFheAkT ${Oscillator_Release_library_list})

set_target_properties(Oscillator_Release_image_gPFheAkT PROPERTIES
    OUTPUT_NAME "Release"
    SUFFIX ".elf"
    ADDITIONAL_CLEAN_FILES "${output_extensions}"
    RUNTIME_OUTPUT_DIRECTORY "${Oscillator_Release_output_dir}")
target_link_libraries(Oscillator_Release_image_gPFheAkT PRIVATE ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_link})

#Add objcopy steps
Oscillator_Release_objcopy_ihex_rule(Oscillator_Release_image_gPFheAkT)
Oscillator_Release_objcopy_eep_rule(Oscillator_Release_image_gPFheAkT)
Oscillator_Release_objcopy_lss_rule(Oscillator_Release_image_gPFheAkT)
Oscillator_Release_objcopy_srec_rule(Oscillator_Release_image_gPFheAkT)
Oscillator_Release_objcopy_sig_rule(Oscillator_Release_image_gPFheAkT)
# Add the link options from the rule file.
Oscillator_Release_link_rule( Oscillator_Release_image_gPFheAkT)


