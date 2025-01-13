## Building and running

<code>git clone https://github.com/beckyfeng08/glEngine.git</code>

<code>cd glEngine</code>

Setting up git submodules:

<code>git submodule init; git submodule update</code>

<code> mkdir build; cd build</code>

Run the following commands in order from the glEngine directory

<code>./configure.sh</code>

<code>./build.sh</code>

<code>./run.sh</code>

Only tested so far for apple arm64
Uses C++11 (to support imgui dependency)

requires at least cmake 3.31.2 to build
