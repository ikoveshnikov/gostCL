typedef struct {
                unsigned int k[8];
                /* Constant s-boxes -- set up in gost_init(). */
                unsigned int k87[256],k65[256],k43[256],k21[256];
} gost_ctx;


inline unsigned int f(__global gost_ctx *c, unsigned int x)
        {
        x = c->k87[x>>24 & 255] | c->k65[x>>16 & 255]|
            c->k43[x>> 8 & 255] | c->k21[x & 255];
        /* Rotate left 11 bits */
        return x<<11 | x>>(32-11);
        }


__kernel void decrypt (__global unsigned int *input,
                       __global unsigned int *output,
                       __global gost_ctx * params)
{
   /* Get the work-item’s unique ID */
   int idx = get_global_id(0);

   output[idx*2] = input[idx*2];
   output[idx*2 +1] = input[idx*2 +1];

   unsigned int n1 = output[idx*2];
   unsigned int n2 = output[idx*2 + 1]; /* As named in the GOST */

        /* Instead of swapping halves, swap names each round */

        n2 ^= f(params,n1+params->k[0]); n1^= f(params,n2+params->k[1]);
        n2 ^= f(params,n1+params->k[2]); n1^= f(params,n2+params->k[3]);
        n2 ^= f(params,n1+params->k[4]); n1^= f(params,n2+params->k[5]);
        n2 ^= f(params,n1+params->k[6]); n1^= f(params,n2+params->k[7]);

        n2 ^= f(params,n1+params->k[7]); n1^= f(params,n2+params->k[6]);
        n2 ^= f(params,n1+params->k[5]); n1^= f(params,n2+params->k[4]);
        n2 ^= f(params,n1+params->k[3]); n1^= f(params,n2+params->k[2]);
        n2 ^= f(params,n1+params->k[1]); n1^= f(params,n2+params->k[0]);

        n2 ^= f(params,n1+params->k[7]); n1^= f(params,n2+params->k[6]);
        n2 ^= f(params,n1+params->k[5]); n1^= f(params,n2+params->k[4]);
        n2 ^= f(params,n1+params->k[3]); n1^= f(params,n2+params->k[2]);
        n2 ^= f(params,n1+params->k[1]); n1^= f(params,n2+params->k[0]);

        n2 ^= f(params,n1+params->k[7]); n1^= f(params,n2+params->k[6]);
        n2 ^= f(params,n1+params->k[5]); n1^= f(params,n2+params->k[4]);
        n2 ^= f(params,n1+params->k[3]); n1^= f(params,n2+params->k[2]);
        n2 ^= f(params,n1+params->k[1]); n1^= f(params,n2+params->k[0]);

    //finaly need to swap n1 and n2
    unsigned int swap = n1;
    output[idx*2] = n2;
    output[idx*2 +1] = swap;
}

__kernel void encrypt (__global unsigned int *input,
                       __global unsigned int *output,
                       __global gost_ctx * params)
{
   /* Get the work-item’s unique ID */
   int idx = get_global_id(0);

   output[idx*2] = input[idx*2];
   output[idx*2 +1] = input[idx*2 +1];

   unsigned int n1 = output[idx*2];
   unsigned int n2 = output[idx*2 + 1]; /* As named in the GOST */

        /* Instead of swapping halves, swap names each round */

        n2 ^= f(params,n1+params->k[0]); n1^= f(params,n2+params->k[1]);
        n2 ^= f(params,n1+params->k[2]); n1^= f(params,n2+params->k[3]);
        n2 ^= f(params,n1+params->k[4]); n1^= f(params,n2+params->k[5]);
        n2 ^= f(params,n1+params->k[6]); n1^= f(params,n2+params->k[7]);

        n2 ^= f(params,n1+params->k[0]); n1^= f(params,n2+params->k[1]);
        n2 ^= f(params,n1+params->k[2]); n1^= f(params,n2+params->k[3]);
        n2 ^= f(params,n1+params->k[4]); n1^= f(params,n2+params->k[5]);
        n2 ^= f(params,n1+params->k[6]); n1^= f(params,n2+params->k[7]);

        n2 ^= f(params,n1+params->k[0]); n1^= f(params,n2+params->k[1]);
        n2 ^= f(params,n1+params->k[2]); n1^= f(params,n2+params->k[3]);
        n2 ^= f(params,n1+params->k[4]); n1^= f(params,n2+params->k[5]);
        n2 ^= f(params,n1+params->k[6]); n1^= f(params,n2+params->k[7]);

        n2 ^= f(params,n1+params->k[7]); n1^= f(params,n2+params->k[6]);
        n2 ^= f(params,n1+params->k[5]); n1^= f(params,n2+params->k[4]);
        n2 ^= f(params,n1+params->k[3]); n1^= f(params,n2+params->k[2]);
        n2 ^= f(params,n1+params->k[1]); n1^= f(params,n2+params->k[0]);

    //finaly need to swap n1 and n2
    unsigned int swap = n1;
    output[idx*2] = n2;
    output[idx*2 +1] = swap;
}

__kernel void crypt_cfb(__global unsigned int *input,
                        __global unsigned int *output,
                        __global gost_ctx * params)
{
   /* Get the work-item’s unique ID */
   int idx = get_global_id(0);

   unsigned int n1 = input[idx*2];
   unsigned int n2 = input[idx*2 +1]; /* As named in the GOST */

        /* Instead of swapping halves, swap names each round */

        n2 ^= f(params,n1+params->k[0]); n1 ^= f(params,n2+params->k[1]);
        n2 ^= f(params,n1+params->k[2]); n1 ^= f(params,n2+params->k[3]);
        n2 ^= f(params,n1+params->k[4]); n1 ^= f(params,n2+params->k[5]);
        n2 ^= f(params,n1+params->k[6]); n1 ^= f(params,n2+params->k[7]);

        n2 ^= f(params,n1+params->k[0]); n1 ^= f(params,n2+params->k[1]);
        n2 ^= f(params,n1+params->k[2]); n1 ^= f(params,n2+params->k[3]);
        n2 ^= f(params,n1+params->k[4]); n1 ^= f(params,n2+params->k[5]);
        n2 ^= f(params,n1+params->k[6]); n1 ^= f(params,n2+params->k[7]);

        n2 ^= f(params,n1+params->k[0]); n1 ^= f(params,n2+params->k[1]);
        n2 ^= f(params,n1+params->k[2]); n1 ^= f(params,n2+params->k[3]);
        n2 ^= f(params,n1+params->k[4]); n1 ^= f(params,n2+params->k[5]);
        n2 ^= f(params,n1+params->k[6]); n1 ^= f(params,n2+params->k[7]);

        n2 ^= f(params,n1+params->k[7]); n1 ^= f(params,n2+params->k[6]);
        n2 ^= f(params,n1+params->k[5]); n1 ^= f(params,n2+params->k[4]);
        n2 ^= f(params,n1+params->k[3]); n1 ^= f(params,n2+params->k[2]);
        n2 ^= f(params,n1+params->k[1]); n1 ^= f(params,n2+params->k[0]);

    //finaly need to swap n1 and n2
    if (idx !=0)
    {
        output[idx*2 +2] = n2 ^ input[idx*2 +2] ;
        output[idx*2 +3] = n1 ^ input[idx*2 +3];
    }
    else
    {
        output[idx*2] = 0;
        output[idx*2 +1] = 0;
    }


}

