//----------------------------------------------------------------------------------------------------
// Hash table node structure
//----------------------------------------------------------------------------------------------------
typedef struct HashNode {
    int key;
    int value;
    struct HashNode *next;
} HashNode;

typedef struct {
    HashNode **buckets;
    int size;
} HashMap;

//----------------------------------------------------------------------------------------------------
// Hash table functions
//----------------------------------------------------------------------------------------------------
HashMap *hashmap_create(int size) {
    HashMap *map = (HashMap *) malloc(sizeof(HashMap));
    if (map == NULL) return NULL;

    map->size = size;
    map->buckets = (HashNode **) calloc(size, sizeof(HashNode *));
    if (map->buckets == NULL) {
        free(map);
        return NULL;
    }
    return map;
}

int hash(int key, int size) {
    int h = key % size;
    return h < 0 ? h + size : h;
}

void hashmap_put(HashMap *map, int key, int value) {
    if (map == NULL) return;
    int index = hash(key, map->size);
    HashNode *node = (HashNode *) malloc(sizeof(HashNode));
    if (node == NULL) return;

    node->key = key;
    node->value = value;
    node->next = map->buckets[index];
    map->buckets[index] = node;
}

int hashmap_get(HashMap *map, int key, int *found) {
    if (map == NULL) {
        if (found != NULL) *found = 0;
        return -1;
    }
    int index = hash(key, map->size);
    HashNode *node = map->buckets[index];

    while (node != NULL) {
        if (node->key == key) {
            *found = 1;
            return node->value;
        }
        node = node->next;
    }

    *found = 0;
    return -1;
}

void hashmap_destroy(HashMap *map) {
    if (map == NULL) return;
    for (int i = 0; i < map->size; i++) {
        HashNode *node = map->buckets[i];
        while (node != NULL) {
            HashNode *temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(map->buckets);
    free(map);
}

//----------------------------------------------------------------------------------------------------
// Two Sum solution
//----------------------------------------------------------------------------------------------------
int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
    HashMap *map = hashmap_create(numsSize * 2);
    if (map == NULL) {
        *returnSize = 0;
        return NULL;
    }

    for (int i = 0; i < numsSize; i++) {
        int difference = target - nums[i];
        int found;
        int index = hashmap_get(map, difference, &found);

        if (found) {
            int *result = (int *) malloc(2 * sizeof(int));
            if (result == NULL) {
                hashmap_destroy(map);
                *returnSize = 0;
                return NULL;
            }
            result[0] = index;
            result[1] = i;
            *returnSize = 2;
            hashmap_destroy(map);
            return result;
        }

        hashmap_put(map, nums[i], i);
    }

    hashmap_destroy(map);
    *returnSize = 0;
    return NULL;
}