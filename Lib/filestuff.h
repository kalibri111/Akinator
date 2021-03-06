//
// Created by kalibri on 09.09.2020.
//

#ifndef STRINGSORT_FILESTUFF_H
#define STRINGSORT_FILESTUFF_H

#endif //STRINGSORT_FILESTUFF_H

#include <stdio.h>
#include <ctype.h>
#include <stddef.h>
#include <stdlib.h>

#include "strview.h"
#include "term_type.h"
#include "file_str.h"

/*
 * аллоцирует заданное количество структур
 * */
struct strview* newIndexPull(size_t n_count);

/*
 * проверяет тип терминирования файла
 * возвращает term_type
 * */
enum term_type termType(const char* file_buffer, size_t buffer_size);

/*
 * создает массив strview, ставит указатель на начало каждого слова
 * необходимо вызывать free() после использования
 * возвращает NULL если termType от buffer INVALID
 * */
struct strview* newIndex(char* file_buffer, size_t index_size, size_t buffer_size);

void destroyIndex(strview_t* index);

/*
 * возвращает размер файла в байтах
 * */
int getFileSize(FILE* file);

/*
 * подсчет количества строк в файле
 * */
int evaluateBuffer(char* buffer, size_t size, char orig, char new_);

/*
 * запись файла в массив построчно, строки разделены \0
 * необходимо вызывать free() после использования
 * */
char* newBufFromFile(FILE* file, size_t buf_size);

void destroyBuffer(char* buffer);

/*
 * запись из массивов в файл построчно
 * */
void indexToFile(const char* file_name, struct strview* index, size_t index_size);

void buffToFile(const char* file_name, char* buffer, size_t buffer_size);

file_str* construct_file_str(FILE* input_file);

void destruct_file_str(file_str* file_str);

void destruct_strview(strview_t* view);

strview_t* new_strview();
