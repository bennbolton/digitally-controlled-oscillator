# The following variables contains the files used by the different stages of the build process.
set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_assemble)
set_source_files_properties(${Oscillator_Release_Release_avr_gcc_FILE_TYPE_assemble} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_assemble})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_assembleWithPreprocess)
set_source_files_properties(${Oscillator_Release_Release_avr_gcc_FILE_TYPE_assembleWithPreprocess} PROPERTIES LANGUAGE ASM)

# For assembly files, add "." to the include path for each file so that .include with a relative path works
foreach(source_file ${Oscillator_Release_Release_avr_gcc_FILE_TYPE_assembleWithPreprocess})
        set_source_files_properties(${source_file} PROPERTIES INCLUDE_DIRECTORIES "$<PATH:NORMAL_PATH,$<PATH:REMOVE_FILENAME,${source_file}>>")
endforeach()

set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_compile)
set_source_files_properties(${Oscillator_Release_Release_avr_gcc_FILE_TYPE_compile} PROPERTIES LANGUAGE C)
set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_compile_cpp)
set_source_files_properties(${Oscillator_Release_Release_avr_gcc_FILE_TYPE_compile_cpp} PROPERTIES LANGUAGE CXX)
set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_link)
set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_ihex)
set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_eep)
set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_lss)
set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_srec)
set(Oscillator_Release_Release_avr_gcc_FILE_TYPE_objcopy_sig)
set(Oscillator_Release_image_name "Release.elf")
set(Oscillator_Release_image_base_name "Release")

# The output directory of the final image.
set(Oscillator_Release_output_dir "${CMAKE_CURRENT_SOURCE_DIR}/../../../out/Oscillator")

# The full path to the final image.
set(Oscillator_Release_full_path_to_image ${Oscillator_Release_output_dir}/${Oscillator_Release_image_name})

# Potential output file extensions
set(output_extensions
    .hex
    .lss
    .eep
    .srec
    .usersignatures)
list(TRANSFORM output_extensions PREPEND "${Oscillator_Release_output_dir}/${Oscillator_Release_image_base_name}")
