unlinker4flash
=============

In many cases it's undesirable that a given (temporary) file be unlinked by some
other program.

A scenario in which I find useful to trick a program into thinking that a files
was unlinked is when libflashplugin.so tries to unlink a temporary-flv video
that I'm currently watching. This is why I created unlinker4flash.

You can effectively override the default implementation preloading the generated
module with `LD_PRELOAD` environment variable.

To cope i386 code generation from a 64-bit code and loading, do the following:

1. Compile the module using 32-bit code generation:

    <pre>
    <code>
    CFLAGS="-m32 -march=i386" DFLAGS="-L/lib32 -L/usr/lib32 -Wl,-rpath,/lib32 \
    -Wl,-rpath,/usr/lib32" make
    </code>
    </pre>

    Note: I am currently on my 64-bit Ubuntu box, so you'll have to replace
    `/lib32` and `/usr/lib32` to whatever your distro have. Also 
    double check if your distro provides multilib support, Ubuntu does.

1. Change the so module's owner and group to root

    <pre>
    <code>
    sudo chown root:root unlinker4flash.so
    </code>
    </pre>

1. Launch your browser

    <pre>
    <code>
    LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/path/to/your/unlinker4flash.so \
    LD_PRELOAD=/path/to/your/unlink.so your-browser &
    </code>
    </pre>

A more permanent solution would be to place an alias for the above invocation in
`$HOME/.profile` and `$HOME/.bashrc` and then moving unlinker4flash.so to 
/usr/lib32.
