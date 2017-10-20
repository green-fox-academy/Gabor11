#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

char ops[14][6];

void defining_ops() {

	strcpy(ops[0], "+");
	strcpy(ops[1], "-");
	strcpy(ops[2], "*");
	strcpy(ops[3], "/");
	strcpy(ops[4], "%");
	strcpy(ops[5], "^");
	strcpy(ops[6], "<");
	strcpy(ops[7], "log");
	strcpy(ops[8], "tobin");
	strcpy(ops[9], "tohex");
   strcpy(ops[10], "todec");
   strcpy(ops[11], "exit");
   strcpy(ops[12], "clear");
   strcpy(ops[13], "help");
}


// this function receives the end of the two arrays and it iterates through them recursively
double do_math(char oprtrs[][6], int o_end, double* nums, int n_end, char ops[14][6], char string_out[], char error_out[])
{
    int i = 0;
    double result = 0;
    if (o_end > 0)
        result = do_math(oprtrs, o_end - 1, nums, n_end - 1, ops, string_out, error_out);
    else if (n_end > 0)
        result = nums[n_end - 1];
    else
        result = nums[n_end]; // this is for operators with one operand
    // choosing the operator
    while (strcmp(oprtrs[o_end], ops[i]) != 0 && i < 14) {
        i++;
    }
    switch (i) {
    case 0:
        return result + nums[n_end];
        break;
    case 1:
        return result - nums[n_end];
        break;
    case 2:
        return result * nums[n_end];
        break;
    case 3:
        return result / nums[n_end];
        break;
    case 4:
        return (int)result % (int)nums[n_end];
        break;
    case 5:
        return pow(result,nums[n_end]);
        break;
    case 6:
        return pow(result, 1/nums[n_end]);
        break;
    case 7:
        return log(nums[n_end])/log(result);
        break;
    case 8: // binto
        itoa((int)result, string_out, 2);
        return DBL_MAX;
        break;
    case 9: // hexto
        itoa((int)result, string_out, 16);
        return DBL_MAX;
        break;
    case 10:
        return result;  // decto
        break;
    case 11:
        return 1;
        // exit
        break;
    case 12:
        return 1;
        // clear
        break;
    case 13:
        return 1;
        // help
        break;
    default:
        return DBL_MAX;

        break;

    }
}

