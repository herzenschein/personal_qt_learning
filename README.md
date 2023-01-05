# ECM KDECompilerSettings

~Why is it that just by including KDECompilerSettings, I get undefined reference to printHello(), yet commenting it works fine?~

KDECompilerSettings sets `-fvisibility=hidden`, so `printHello()` is hidden by default.

`__attribute__((visibility("default")))` / `[[gnu::visibility("default")]]` works, but KDE doesn't seem to make use of these everywhere.

`generate_export_header()` , `ecm_generate_headers()` and `ecm_generate_export_header()` don't seem to be used for this, or at least I didn't find out how to use them correctly.

What am I missing?
