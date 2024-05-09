import os
import subprocess
from sys import platform

env = Environment(ENV=os.environ)
env.Tool("compilation_db")
env.CompilationDatabase()

env.Append(
    CXXFLAGS=[
        # "-O0",
        # "-g",
        "-O3",
        "-Wall",
        "-Wextra",
        "-pedantic",
        "-std=c++17",
    ]
)

# Set environment

# Export environment
Export("env")

# Run SConscript files
SConscript("SConscript")
