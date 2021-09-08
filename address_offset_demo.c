#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t HAL_GetTreeOffset(const uint32_t *tree_id, uint32_t *tree_offset) {
    uint32_t data[] = {0XEEEEEEEC, 4, 1, 0XEEEEEEEC, 2, 0XEEEEEEED, 3, 0XEEEEEEEE, 4, 0XEEEEEEEF};

    uint32_t *offset = data;
    offset += 1;
    uint32_t tree_count = *offset;
    offset += 1;

    uint32_t mem_tree_id;
    for (int i = 0; i < tree_count; i++) {
        mem_tree_id = *offset;
        if (mem_tree_id == *tree_id) {
            *tree_offset = *(offset + 1);
            return 0;
        }
        offset += 2;
    }
    return 1;
}

int main(int argc, char *args[]) {

    uint32_t tree_id = 1;
    uint32_t *tree_offset = malloc(sizeof(uint32_t));
    HAL_GetTreeOffset(&tree_id, tree_offset);
    printf("%d, %p\n", tree_id, tree_offset);
    printf("%d, %u\n", tree_id, *tree_offset);
    tree_id = 2;
    HAL_GetTreeOffset(&tree_id, tree_offset);
    printf("%d, %p\n", tree_id, tree_offset);
    printf("%d, %u\n", tree_id, *tree_offset);
    tree_id = 3;
    HAL_GetTreeOffset(&tree_id, tree_offset);
    printf("%d, %p\n", tree_id, tree_offset);
    printf("%d, %u\n", tree_id, *tree_offset);
    tree_id = 4;
    HAL_GetTreeOffset(&tree_id, tree_offset);
    printf("%d, %p\n", tree_id, tree_offset);
    printf("%d, %u\n", tree_id, *tree_offset);
}

