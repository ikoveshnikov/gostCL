__kernel
void vecadd(__global int *input,
            __global int *output,
            __global int *key)
{
   // Get the work-item’s unique ID
   int idx = get_global_id(0);

   // Add the corresponding locations of
   // 'A' and 'B', and store the result in 'C'.
   output[idx] = input[idx];
}

