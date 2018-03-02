#include <string>
#include <vector>
#include <iostream>

/*typedef struct cacheSlice {
	int value;
	int frequency;
} cacheSlice;

typedef struct frequencyTable {
	
} fre;*/
#ifndef NULL
#define NULL 0
#endif
using namespace std;
class cacheTableSlice;
class frequencyCount;
class frequencyTable;

class cacheTableSlice {
public:
	cacheTableSlice(int key_, int value_, int frequency_): key(key_), value(value_),frequency(frequency_){}
	cacheTableSlice(): key(0), value(0), frequency(0) {};
	friend class frequencyTable;
	friend class LFUCache;
	friend class hashtable;
	void addFrequency(frequencyTable& table);
private:
	int key;
	int value;
	int frequency;

};

class frequencyCount {
public:
	frequencyCount(cacheTableSlice* block_, frequencyCount* next_, frequencyCount* before_): block(block_), next(next_), before(before_) {};
	frequencyCount(): block(NULL), next(NULL), before(NULL) {}
	friend class frequencyTable;
	friend class LFUCache;
private:
	cacheTableSlice* block;
	frequencyCount* next;
	frequencyCount* before;
};


class frequencyTable {
public:
#define TABLESIZE 10000
	frequencyTable(): table(TABLESIZE,frequencyCount()) {};
	friend class LFUCache;
	cacheTableSlice* minimum() {
		int i;
		for(i=0;i<TABLESIZE;i++){
			if(table[i].block!=NULL){
				return table[i].block;
			}
		}
		return NULL;
	};
	int removeSlice(int frec, cacheTableSlice* slice) {
		if( table[frec].block == slice ){
			if(table[frec].next == &(table[frec])) {
				table[frec].block = NULL;
			} else {
				auto temp = table[frec].next;
				if(table[frec].before == temp){
					table[frec].before = &(table[frec]);
				}
				table[frec].block = temp->block;
				table[frec].next = temp->next;
				delete temp;
			}
		} else {
			frequencyCount* iter = table[frec].next;
			for( ;iter->block != slice; iter = iter->next){};
			iter->before->next = iter->next;
			iter->next->before = iter->before;
			delete iter;
		}
		return 0;
	}
	int addSlice(int frec, cacheTableSlice* slice) {
		if(table[frec].block == NULL) {
			table[frec].block = slice;
			table[frec].before = &(table[frec]);
			table[frec].next = &(table[frec]);
			return 0;
		} else {
			auto temp = new frequencyCount();
			temp->block = slice;
			temp->before = table[frec].before;
			temp->next = &(table[frec]);
			table[frec].before->next = temp;
			table[frec].before = temp;
			return 0;
		}
	}
private:
	vector<frequencyCount> table;
};


void cacheTableSlice::addFrequency(frequencyTable& table) {
	if(frequency<TABLESIZE-1){
		table.removeSlice(frequency,this);
		frequency += 1;
		table.addSlice(frequency,this);
	} else {}
}

class hashlist {
public:
	hashlist(cacheTableSlice* block_, hashlist* next_):block(block_),next(next_) {};
	hashlist():block(NULL),next(NULL){};
	friend class hashtable;
private:
	cacheTableSlice* block;
	hashlist* next;
};

class hashtable {
public:
	hashtable(int size_): table(size_+100,NULL), size(size_+100){};
	cacheTableSlice* locate(int key);
	void removeBlock(int key);
	void addBlock(cacheTableSlice* slice);
private:
	vector<hashlist*> table;
	int size;
};

cacheTableSlice* hashtable::locate(int key) {
	int i = key % size;
	hashlist* iter = table[i];
	if(iter==NULL) return NULL;
	for( ; iter->block->key != key && iter->next != NULL; iter = iter->next){}
	if(iter->block->key == key)
		return iter->block;
	else return NULL;
}

void hashtable::removeBlock(int key) {
	int i = key % size;
	if (table[i]->block->key == key) {
		auto temp = table[i];
		table[i] = table[i]->next;
		delete temp;
	} else {
		auto iter = table[i];
		while(iter->next->block->key != key) {
			iter = iter -> next;
		}
		if(iter->next == NULL) {
		} else {
			auto temp = iter->next;
			iter->next = iter->next->next;
			delete temp;
		}
	}
}

void hashtable::addBlock(cacheTableSlice* slice){
	int i = slice->key % size;
	hashlist* block = new hashlist(slice, table[i]);
	table[i] = block;
}

class LFUCache {
public:
	friend class frequencyTable;
    LFUCache(int capacity):cacheTable(vector<cacheTableSlice>(capacity)){
		free = cacheTable.begin();
        frecTable = new frequencyTable();
		hash = new hashtable(capacity);
    }
    
    int get(int key) {
        cacheTableSlice* block = hash->locate(key);
		if(block == NULL){
			return -1;
		}
		int result = block -> value;
		block->addFrequency(*frecTable);
		return result;
    }
    
    void put(int key, int value) {
		cacheTableSlice* block = hash->locate(key);
		if(block != NULL){
			block->value = value;
			block->addFrequency(*frecTable);
		} else {
			if(free!=cacheTable.end()){
				free->key = key;
				free->value = value;
				free->frequency = 0;
				frecTable->addSlice(0,&*free);
				hash->addBlock(&*free);
				free++;
			} else {
				auto slice = frecTable->minimum();
				if(slice != NULL){
					hash->removeBlock(slice->key);
					frecTable->removeSlice(slice->frequency,slice);
					slice->key = key;
					slice->value = value;
					slice->frequency = 0;
					frecTable->addSlice(0,slice);
					hash->addBlock(slice);
				}
			}
		}
    }
private:
	vector<cacheTableSlice> cacheTable;
	frequencyTable* frecTable;
	hashtable* hash;
	vector<cacheTableSlice>::iterator free;
};


/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
