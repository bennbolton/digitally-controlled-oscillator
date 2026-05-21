# The following functions contains all the flags passed to the different build stages.

set(PACK_REPO_PATH "C:/Users/bb155134/.mchp_packs" CACHE PATH "Path to the root of a pack repository.")

function(Oscillator_Release_Release_avr_gcc_assemble_rule target)
    set(options
        "-x"
        "assembler-with-cpp"
        "${MP_EXTRA_AS_PRE}"
        "-mmcu=atxmega256a3bu"
        "-BC:/Program Files (x86)/Atmel/Studio/7.0/Packs/atmel/XMEGAA_DFP/1.3.146/gcc/dev/atxmega256a3bu"
        "-c"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST},--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--gdwarf-2,-g")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "DEBUG"
        PRIVATE "__ATxmega256A3BU__"
        PRIVATE "Release=Release")
    target_include_directories(${target} PRIVATE "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/atmel/XMEGAA_DFP/1.3.146/include")
endfunction()
function(Oscillator_Release_Release_avr_gcc_assembleWithPreprocess_rule target)
    set(options
        "-x"
        "assembler-with-cpp"
        "${MP_EXTRA_AS_PRE}"
        "-mmcu=atxmega256a3bu"
        "-BC:/Program Files (x86)/Atmel/Studio/7.0/Packs/atmel/XMEGAA_DFP/1.3.146/gcc/dev/atxmega256a3bu"
        "-c"
        "-Wa,--defsym=__MPLAB_BUILD=1${MP_EXTRA_AS_POST},--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--gdwarf-2,-g")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "DEBUG"
        PRIVATE "__ATxmega256A3BU__"
        PRIVATE "Release=Release")
    target_include_directories(${target} PRIVATE "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/atmel/XMEGAA_DFP/1.3.146/include")
endfunction()
function(Oscillator_Release_Release_avr_gcc_compile_rule target)
    set(options
        "-g"
        "-gdwarf-2"
        "${MP_EXTRA_CC_PRE}"
        "-mmcu=atxmega256a3bu"
        "-BC:/Program Files (x86)/Atmel/Studio/7.0/Packs/atmel/XMEGAA_DFP/1.3.146/gcc/dev/atxmega256a3bu"
        "-x"
        "c"
        "-c"
        "-funsigned-char"
        "-funsigned-bitfields"
        "-Os"
        "-ffunction-sections"
        "-fdata-sections"
        "-fpack-struct"
        "-fshort-enums"
        "-Wall")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "DEBUG"
        PRIVATE "__ATxmega256A3BU__"
        PRIVATE "NDEBUG"
        PRIVATE "Release=Release")
    target_include_directories(${target} PRIVATE "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/atmel/XMEGAA_DFP/1.3.146/include")
endfunction()
function(Oscillator_Release_Release_avr_gcc_compile_cpp_rule target)
    set(options
        "-g"
        "-gdwarf-2"
        "${MP_EXTRA_CC_PRE}"
        "-mmcu=atxmega256a3bu"
        "-BC:/Program Files (x86)/Atmel/Studio/7.0/Packs/atmel/XMEGAA_DFP/1.3.146/gcc/dev/atxmega256a3bu"
        "-x"
        "c++"
        "-c"
        "-O0"
        "-ffunction-sections"
        "-fdata-sections")
    list(REMOVE_ITEM options "")
    target_compile_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "DEBUG"
        PRIVATE "__ATxmega256A3BU__"
        PRIVATE "Release=Release")
    target_include_directories(${target} PRIVATE "C:/Program Files (x86)/Atmel/Studio/7.0/Packs/atmel/XMEGAA_DFP/1.3.146/include")
endfunction()
function(Oscillator_Release_link_rule target)
    set(options
        "-gdwarf-2"
        "${MP_EXTRA_LD_PRE}"
        "-mmcu=atxmega256a3bu"
        "-BC:/Program Files (x86)/Atmel/Studio/7.0/Packs/atmel/XMEGAA_DFP/1.3.146/gcc/dev/atxmega256a3bu"
        "-Wl,--defsym=__MPLAB_BUILD=1${MP_EXTRA_LD_POST},--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1"
        "-Wl,--gc-sections")
    list(REMOVE_ITEM options "")
    target_link_options(${target} PRIVATE "${options}")
    target_compile_definitions(${target}
        PRIVATE "__ATxmega256A3BU__"
        PRIVATE "Release=Release")
    target_link_libraries(${target} PRIVATE "m")
endfunction()
function(Oscillator_Release_objcopy_ihex_rule target)
    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${OBJCOPY}
        ARGS --output-target=ihex ${Oscillator_Release_image_name} ${Oscillator_Release_image_base_name}.hex
        WORKING_DIRECTORY ${Oscillator_Release_output_dir})
endfunction()
function(Oscillator_Release_objcopy_eep_rule target)
    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${OBJCOPY}
        ARGS --only-section=.eeprom --change-section-lma .eeprom=0 --no-change-warnings --output-target=ihex ${Oscillator_Release_image_name} ${Oscillator_Release_image_base_name}.eep
        WORKING_DIRECTORY ${Oscillator_Release_output_dir})
endfunction()
function(Oscillator_Release_objcopy_lss_rule target)
    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${OBJDUMP}
        ARGS --disassemble --wide --demangle --line-numbers --section-headers --source ${Oscillator_Release_image_name} > ${Oscillator_Release_image_base_name}.lss
        WORKING_DIRECTORY ${Oscillator_Release_output_dir})
endfunction()
function(Oscillator_Release_objcopy_srec_rule target)
    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${OBJCOPY}
        ARGS --output-target=srec --remove-section=.eeprom --remove-section=.fuse --remove-section=.lock --remove-section=.signature ${Oscillator_Release_image_name} ${Oscillator_Release_image_base_name}.srec
        WORKING_DIRECTORY ${Oscillator_Release_output_dir})
endfunction()
function(Oscillator_Release_objcopy_sig_rule target)
    add_custom_command(
        TARGET ${target}
        POST_BUILD
        COMMAND ${OBJCOPY}
        ARGS --only-section=.user_signatures --change-section-lma .user_signatures=0 --no-change-warnings --output-target=ihex ${Oscillator_Release_image_name} ${Oscillator_Release_image_base_name}.usersignatures
        WORKING_DIRECTORY ${Oscillator_Release_output_dir})
endfunction()
