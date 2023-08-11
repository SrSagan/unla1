#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

void mostrar_test(struct Test m)
{
    m.test=10;
    printf("%d", m.test);
}
