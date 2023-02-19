
SCRIPT=$(readlink -f "$0")
CURRENT_DIR=$(dirname "$SCRIPT")
SHADERS_DIR=$CURRENT_DIR/shaders
echo "Shaders Dir: $SHADERS_DIR"

glslc $SHADERS_DIR/shader.vert -o $SHADERS_DIR/vert.spv
glslc $SHADERS_DIR/shader.frag -o $SHADERS_DIR/frag.spv
