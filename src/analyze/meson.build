# SPDX-License-Identifier: LGPL-2.1-or-later

systemd_analyze_sources = files('''
        analyze.c
        analyze-condition.c
        analyze-condition.h
        analyze-elf.c
        analyze-elf.h
        analyze-verify.c
        analyze-verify.h
        analyze-security.c
        analyze-security.h
'''.split())

tests += [
        [files('test-verify.c',
               'analyze-verify.c',
               'analyze-verify.h'),
         [libcore,
          libshared],
         [],
         core_includes],
]
