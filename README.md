# to compile on Linux:

1) Makefile
change line 27 (change path to the mlx library from mlx/ to mlx_linux/)

    MLX = mlx_linux/libmlx.a

change line 52
    @ make -C mlx_linux/ >/dev/null

2) inc/execution.h
lines 23 - 31 (change key hooks codes)

    #define W	119 //13 macos

    #define A	97 //0 macos

    #define S	115	//1 macos

    #define D	100	//2 macos

    #define UP	65362 //126 macos

    #define DOWN 65364 //125 macos

    #define LEFT	65361 //123 macos

    #define RIGHT	65363 //124 macos

    #define ESC	65307	//53 macos

3) src/execution/execution_strt.c
line 84 (change mlx_hook mask argument from 0 to 1)
  
    mlx_hook((*iData)->win_ptr, 2, 1, key_hook, iData);


# to detect memory leaks with valgrind suppresing mlx leaks use
    valgrind --leak-check=full --suppresed=test_src/scripts/supp.supp
