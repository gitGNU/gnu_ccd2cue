/**
 * \file       memory.h
 * \brief      Memory management
 * \author     Bruno Félix Rezende Ribeiro (_oitofelix_)
 *             <oitofelix@gmail.com>
 * \date       2013
 * \version    0.2
 *
 * \copyright [GNU General Public License (version 3 or later)]
 *            (http://www.gnu.org/licenses/gpl.html)
 *
 * ~~~
 * This file is part of ccd2cue.
 *
 * ccd2cue is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * ccd2cue is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * ~~~
 *
 */


#ifndef CCD2CUE_MEMORY_H
#define CCD2CUE_MEMORY_H

#include <stddef.h>

/**
 * Obstack chunk allocate function;
 *
 * This function is called to allocate chunks of memory into which
 * obstack objects are packed.
 *
 * \sa [Preparing for Using Obstacks] (https://gnu.org/software/libc/manual/html_node/Preparing-for-Obstacks.html#Preparing-for-Obstacks)
 *
 */

#define obstack_chunk_alloc xmalloc

/**
 * Obstack chunk free function;
 *
 * This function is called to return chunks of memory when the obstack
 * objects in them are freed.
 *
 * \sa [Preparing for Using Obstacks] (https://gnu.org/software/libc/manual/html_node/Preparing-for-Obstacks.html#Preparing-for-Obstacks)
 *
 */

#define obstack_chunk_free free

/**
 * Allocate memory.
 *
 * \param[in] size Block size in bytes;
 * 
 * \return A pointer to the newly allocated block;
 *
 * \since 0.2
 *
 * This function returns a pointer to a newly allocated block SIZE
 * bytes long, or exits with failure if the block could not be
 * allocated.  It is just a wrapper around `malloc'.
 *
 * \sa [Basic Memory Allocation] (https://gnu.org/software/libc/manual/html_node/Basic-Allocation.html#Basic-Allocation)
 *
 */

void * xmalloc (size_t size)
  __attribute__ ((malloc, alloc_size (1), warn_unused_result));

/**
 * Reallocate memory.
 *
 * \param[in] ptr Block address;
 * \param[in] newsize New size in bytes;
 *
 * \return The new address of the block;
 *
 * \since 0.2
 *
 * This function changes the size of the block whose address is PTR to
 * be NEWSIZE.  If it succeeds, the address of the newly allocated
 * block is returned.  If it is not possible to reallocate the memory
 * block this function exits with failure.  It is just a wrapper
 * around `realloc'.
 *
 * \sa [Changing the Size of a Block] (https://gnu.org/software/libc/manual/html_node/Changing-Block-Size.html#Changing-Block-Size)
 *
 **/

void * xrealloc (void *ptr, size_t newsize)
  __attribute__ ((alloc_size (2), warn_unused_result));
  
#endif	/* CCD2CUE_MEMORY_H */