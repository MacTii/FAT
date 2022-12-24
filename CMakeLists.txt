#
# DANTE :: System Automatycznych Testów Jednostkowych oraz Akceptacyjnych
# Tomasz Jaworski, 2018-2020
#
# Plik wygenerowany automatycznie
# Znacznik czasowy: 2022-12-12 22:37:26.103704
#

cmake_minimum_required(VERSION 3.16)
project(FAT C)

# Przyjmij standard C11
set(CMAKE_C_STANDARD 11)

# Ustaw opcje kompilatora (z raportu Dante)
add_compile_options(
        "-ggdb3"
        "-xc"
        "-Werror=vla"
        "-fmax-errors=5"
        "-Wno-error=unused-parameter"
        "-DINSIDE_DANTE"
        "-std=c11"
        "-Wno-error=implicit-fallthrough"
        "-D_ANSI_OUTPUT"
        "-Wall"
        "-Wextra"
        "-Wno-error=parentheses"
        "-Wno-parentheses"
        "-D_GNU_SOURCE"
        "-pedantic"
        "-fdiagnostics-color"
        "-Werror"

)

# Ustaw opcje konsolidatora (z raportu Dante)
add_link_options(
        "-ggdb3"
        "-Wl,-wrap,main"
        "-Wl,-cref"
        "-Wl,-Map=main.map"
)

# Utwórz target 'project1' i dodaj do niego pliki źródlowe:
add_executable(FAT
        "file_reader.c"
        "main.c"
        "unit_helper_v2.c"
        "unit_test_v2.c"
        "rdebug.c"
        )

# Dołącz niezbędne biblioteki
target_link_libraries(FAT
        "m"
        )