#include <stdint.h>
#include <stdlib.h>

struct bl_sym_pair { const char* name; uintptr_t offset; };
extern struct bl_sym_pair bl_sym_pairs[];
extern int bl_sym_pairs_count;

static uintptr_t bl_mcpe_base;

void bl_fakeSyms_initOneAddress(void** ptr, uintptr_t baseAddr, uintptr_t offset) {
	*ptr = (void*)(baseAddr + offset);
}

static int bl_fakeSyms_bsearch_compare(const struct bl_sym_pair* key, const struct bl_sym_pair* value) {
	return strcmp(key->name, value->name);
}

void* bl_fakeSyms_dlsym(const char* symbolName) {
	if (!bl_mcpe_base) return NULL;
	struct bl_sym_pair key = {
		.name = symbolName,
		.offset = 0,
	};
	// expecting a hand-coded optimized hashtable? Too bad: I'm not as smart as McMrARM.
	struct bl_sym_pair* value = bsearch(&key, bl_sym_pairs, bl_sym_pairs_count, sizeof(key), bl_fakeSyms_bsearch_compare);
	if (!value) return NULL;
	return (void*)(bl_mcpe_base + value->offset);
}

void bl_fakeSyms_initStubs(uintptr_t mcpe_base);

void bl_fakeSyms_init(uintptr_t mcpe_base) {
	bl_mcpe_base = mcpe_base;
	bl_fakeSyms_initStubs(bl_mcpe_base);
}