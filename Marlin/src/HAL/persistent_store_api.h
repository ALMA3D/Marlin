/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include <stddef.h>
#include <stdint.h>

class PersistentStore {
public:
  static bool access_start();
  static bool access_finish();
  static bool write_data(int &pos, const uint8_t *value, size_t size, uint16_t *crc);
  static bool read_data(int &pos, uint8_t* value, size_t size, uint16_t *crc, const bool writing=true);
  static bool write_data(const int pos, uint8_t* value, size_t size);
  static bool read_data(const int pos, uint8_t* value, size_t size);
  static const size_t capacity();
};

extern PersistentStore persistentStore;