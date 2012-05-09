#pragma once

#include <DB/Core/Defines.h>


namespace DB
{

/** Настройки выполнения запроса.
  */
struct Settings
{
	size_t max_block_size;	/// Максимальный размер блока для чтения
	size_t max_threads;		/// Максимальное количество потоков выполнения запроса
	size_t max_query_size;	/// Какую часть запроса можно прочитать в оперативку для парсинга (оставшиеся данные для INSERT, если есть, считываются позже)
	bool asynchronous;		/// Выполнять разные стадии конвейера выполнения запроса параллельно
	size_t interactive_delay; /// Интервал в микросекундах для проверки, не запрошена ли остановка выполнения запроса, и отправки прогресса.

	Settings() :
		max_block_size(DEFAULT_BLOCK_SIZE),
		max_threads(DEFAULT_MAX_THREADS),
		max_query_size(DEFAULT_MAX_QUERY_SIZE),
		asynchronous(true),
		interactive_delay(DEFAULT_INTERACTIVE_DELAY) {}
};


}
