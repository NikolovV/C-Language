float pow_custom(float number, int base)
{
    int i;
    float num = 1;
    for (i = 0; i < base; i++)
    {
        num *= number;
    }

    return num;
}
