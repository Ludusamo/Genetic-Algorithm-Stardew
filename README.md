# Genetic-Algorithm-Stardew

## Project

This is a project to create Genetic Algorithm to identify optimal arrangements of normal sprinklers in [Stardew Valley](http://stardewvalley.net/).

For additional information, check out my blog posts on this topic at my [blog](ludusamo.com/Blog). The first post is [here](http://ludusamo.com/Blog/side-project-genetic-algorithms/index.html).

## How to Use

### In Your Browser

To check out the program running, the easiest way to see it is to go to http://ludusamo.com/Genetic-Algorithm-Stardew. 

At this site, there is an [Emscripten](http://kripken.github.io/emscripten-site/) generated version of this program.

It runs slower than a compiled version, but it works pretty well as a demo.

### Compiled

Alternatively, you can compile it from source which is offered right [here](https://github.com/Ludusamo/Genetic-Algorithm-Stardew) on GitHub.

I am not going to add instructions on how to compile it. There is a Makefile inside here that can help you out. But, I will mention the dependencies:

- clang (if you use the Makefile)
- SDL2
- SDL2_ttf
- SDL2_image
