#ifndef EDGENEURON_H
#define EDGENEURON_H

#include <Arduino.h>
#include <Chirale_TensorFlowLite.h>
#include <tensorflow/lite/micro/all_ops_resolver.h>
#include <tensorflow/lite/micro/micro_interpreter.h>
#include <tensorflow/lite/schema/schema_generated.h>

// Initializes the model and prepares the interpreter for inference.
// model: Pointer to the TFLite model in memory.
// tensorArena: Buffer for holding tensor memory.
// tensorArenaSize: Size of the tensor memory buffer.
// Returns true if initialization was successful, otherwise false.
bool modelInit(const unsigned char* model, byte* tensorArena, int tensorArenaSize);

// Sets the input value at a given index in the input tensor.
// inputValue: The value to set.
// index: Index in the input tensor to place the value.
// Returns true if the input was successfully set, otherwise false.
bool modelSetInput(float inputValue, int index);

// Runs inference on the model.
// Returns true if inference was successful, otherwise false.
bool modelRunInference();

// Gets the output value at a given index in the output tensor.
// index: The index in the output tensor to retrieve the value from.
// Returns the output value or -1 if an error occurred.
float modelGetOutput(int index);

#endif  // EDGENEURON_H
