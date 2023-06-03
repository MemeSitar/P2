#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga2.h"

#define _M 10001

int _A[] = {9974, 9192, 5659, 2632, 86, 4297, 1278, 9496, 9902, 984, 6422, 938, 4337, 9295, 6341, 4825, 3764, 3616, 190, 3205, 5298, 7227, 9491, 6359, 4345, 9815, 3946, 4048, 3060, 4051, 4500, 3466, 3052, 972};
int _B[] = {686, 1054, 1762, 3476, 3611, 5668, 236, 9766, 2212, 1301, 1302, 5105, 4119, 3322, 2106, 2938, 4027, 6394, 6864, 1757, 6267, 855, 6263, 482, 8529, 828, 1605, 5144, 6354, 6059, 918, 2166, 7565, 2761, 9633, 1676, 4970, 8865, 8404, 7779, 6852, 3375, 4060, 1878, 3537, 5726, 9740, 4424, 5849, 9763, 1770, 3458, 7724, 9744, 821, 1696, 717, 4205, 8931, 3040, 5402, 3362, 7354, 5035, 833, 6984, 8639, 2641, 938, 354, 7723, 221, 3799, 8358, 2292, 3813, 1695, 9885, 3445, 8363, 9192, 8965, 5314, 8658, 220, 3156, 5927, 3279, 477, 2601, 1669, 1841, 9115, 8016, 3822, 5199, 3972, 5298, 3377, 1278, 2146, 2655, 7853, 1717, 5352, 8122, 5338, 7011, 984, 9031, 7411, 6720, 9496, 130, 5583, 4051, 3686, 3944, 6856, 185, 106, 9016, 6182, 6999, 4396, 1952, 3850, 9431, 1538, 6437, 17, 123, 7654, 5657, 7078, 453, 9935, 3764, 6662, 6341, 4894, 7294, 5794, 5845, 5353, 9880, 2891, 771, 2507, 8720, 9147, 3006, 89, 8854, 8214, 5873, 4652, 365, 3599, 5847, 5505, 6682, 1266, 6042, 8354, 6460, 8683, 1922, 4337, 8812, 509, 4090, 633, 6525, 8137, 3796, 3865, 9143, 5809, 8454, 2915, 3410, 3153, 3216, 5291, 2552, 6172, 5708, 6986, 1694, 2959, 6204, 2907, 8483, 9423, 3738, 8425, 4152, 846, 9815, 9811, 1225, 2861, 2588, 647, 4015, 3616, 5659, 2594, 1552, 5790, 7227, 1377, 3469, 3030, 6060, 8509, 8316, 461, 834, 5009, 5461, 4511, 2487, 86, 6250, 8595, 9330, 190, 4709, 4713, 7772, 8604, 4492, 2563, 8416, 2066, 2878, 8926, 7282, 1811, 4098, 4341, 2244, 27, 8357, 6655, 134, 8313, 4207, 1780, 9336, 8002, 3567, 5718, 7835, 2260, 2902, 8770, 3527, 2762, 6303, 1242, 1522, 1509, 4184, 5731, 2109, 2643, 3205, 8918, 8579, 2851, 2350, 6906, 1765, 5281, 5455, 3842, 5605, 7403, 6120, 382, 2253, 7442, 3869, 3113, 9295, 7432, 8575, 9672, 3054, 5649, 1449, 3260, 5013, 6470, 8427, 5366, 8222, 8526, 5943, 974, 6135, 8240, 4951, 5756, 3697, 2960, 5950, 732, 1546, 9801, 9777, 1154, 2366, 2008, 7260, 1830, 3423, 5471, 4075, 4635, 4771, 9085, 2242, 2014, 40, 5974, 5758, 7317, 3302, 4502, 2653, 2632, 154, 5080, 798, 5885, 5482, 6000, 2564, 9747, 3719, 9121, 9069, 6454, 1671, 6422, 8209, 5980, 5162, 774, 2268, 5306, 4971, 8128, 3510, 4338, 9132, 4047, 1464, 8758, 7863, 2684, 4297, 8378, 1536, 4403, 5988, 6904, 4089, 909, 6708, 6725, 9554, 2321, 448, 6411, 8496, 2449, 6729, 9991, 9476, 7846, 7147, 6017, 2073, 2380, 4860, 8230, 2160, 1924, 2234, 6231, 2598, 7572, 8833, 5285, 9724, 2523, 6927, 4500, 9549, 7891, 4408, 2559, 5911, 4701, 2337, 5755, 8785, 2638, 8850, 2132, 9817, 3535, 7309, 3466, 268, 699, 2586, 9816, 1340, 5961, 3518, 5171, 7672, 5454, 5641, 3096, 6815, 6992, 4345, 4031, 7051, 9698, 2470, 3728, 4023, 7071, 486, 5462, 5460, 7466, 5955, 8663, 5085, 1981, 4286, 6647, 7979, 5125, 5567, 3013, 2355, 9045, 9316, 2722, 8634, 1832, 3641, 4355, 8225, 165, 1958, 3582, 7528, 9220, 7190, 6291, 1803, 6406, 802, 4736, 6417, 5866, 1595, 954, 8423, 2709, 3150, 9761, 4983, 7647, 2405, 4439, 317, 5053, 4671, 9491, 6748, 4108, 4251, 2445, 6529, 558, 5603, 4989, 3351, 8676, 3785, 58, 5407, 1174, 6609, 7107, 5295, 5786, 8691, 7462, 2918, 9708, 3488, 2730, 4179, 3285, 2153, 7288, 4666, 4000, 4012, 9054, 4889, 5007, 7966, 1839, 1715, 5867, 5820, 9902, 4674, 4391, 5086, 9001, 5565, 7637, 9943, 5088, 5316, 7950, 7096, 5699, 4721, 9745, 874, 3408, 7116, 1373, 7093, 3124, 8607, 2557, 5082, 7315, 9388, 3999, 6607, 936, 8768, 9301, 3996, 5299, 6439, 2276, 7241, 2804, 7681, 6671, 5508, 770, 8890, 8501, 4525, 4475, 7296, 3508, 1597, 9520, 6980, 4091, 9593, 1874, 749, 4243, 348, 3202, 3385, 9947, 4327, 4279, 3926, 4825, 2895, 327, 2930, 8133, 5660, 4212, 4679, 6481, 3553, 9741, 6644, 6679, 7766, 6253, 886, 1439, 4950, 4281, 4718, 3820, 2093, 925, 1363, 1079, 562, 2302, 2272, 8219, 4731, 5001, 440, 4048, 5141, 5401, 9677, 3657, 5036, 7208, 7507, 3350, 4569, 4986, 229, 8445, 5821, 4195, 4136, 3378, 9177, 3333, 7557, 2122, 4200, 1643, 1282, 9625, 3269, 8608, 1645, 3482, 4895, 9359, 472, 8356, 6374, 6192, 704, 9974, 9405, 997, 2338, 4044, 959, 6359, 5491, 683, 7469, 4029, 4629, 8981, 9104, 964, 2773, 9122, 728, 6792, 8076, 5446, 9876, 4803, 8288, 6524, 9178, 4918, 5848, 2713, 696, 4442, 526, 1062, 9799, 3052, 6744, 3563, 1635, 1027, 7361, 5078, 6920, 663, 4662, 8705, 3383, 4636, 6140, 5737, 6592, 3060, 4328};
Vozlisce* _I2A[_M];
Vozlisce* _I2B[_M];

Vozlisce* _izTabele(int* t, int n, Vozlisce** i2v) {
    if (n == 0) {
        return NULL;
    }
    Vozlisce* v = malloc(sizeof(Vozlisce));
    v->podatek = *t;
    i2v[*t] = v;
    v->naslednje = _izTabele(t + 1, n - 1, i2v);
    return v;
}

void _izpisi(Vozlisce* v) {
    printf("[");
    Vozlisce* w = v;
    while (w != NULL) {
        printf("%s%d", (w == v ? "" : ", "), w->podatek);
        w = w->naslednje;
    }
    printf("]\n");
}

void _istovetnost(Vozlisce* v, Vozlisce** i2v) {
    for (Vozlisce* w = v; w != NULL; w = w->naslednje) {
        printf("%d", w == i2v[w->podatek]);
    }
    printf("\n");
}

void _pocisti(Vozlisce* v) {
    if (v != NULL) {
        _pocisti(v->naslednje);
        free(v);
    }
}

int main() {
    Vozlisce* a = _izTabele(_A, sizeof(_A) / sizeof(int), _I2A);
    Vozlisce* b = _izTabele(_B, sizeof(_B) / sizeof(int), _I2B);

    printf("Prej:\n");
    _izpisi(a);
    _izpisi(b);
    printf("\n");

    Vozlisce* na = NULL;
    Vozlisce* nb = NULL;
    izlociSkupne(a, b, &na, &nb);

    printf("Potem:\n");
    _izpisi(na);
    _izpisi(nb);
    printf("\n");

    printf("Istovetnost ohranjenih vozlisc:\n");
    _istovetnost(na, _I2A);
    _istovetnost(nb, _I2B);

    _pocisti(na);
    _pocisti(nb);

    return 0;
}
