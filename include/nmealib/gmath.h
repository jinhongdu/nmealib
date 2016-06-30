/*
 * This file is part of nmealib.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __NMEALIB_GMATH_H__
#define __NMEALIB_GMATH_H__

#include <nmealib/info.h>

#ifdef  __cplusplus
extern "C" {
#endif /* __cplusplus */

#define NMEA_TUD_YARDS              (1.0936133)                     /**< Yards, meter * NMEA_TUD_YARDS = yard */
#define NMEA_TUD_KNOTS              (1.852)                         /**< Knots, kilometer / NMEA_TUD_KNOTS = knot */
#define NMEA_TUD_MILES              (1.609344)                      /**< Miles, kilometer / NMEA_TUD_MILES = mile */
#define NMEA_TUS_MS                 (3.6)                           /**< Meters per seconds, (k/h) / NMEA_TUS_MS= (m/s) */
#define NMEA_PI                     (3.141592653589793)             /**< PI value */
#define NMEA_PI180                  (NMEA_PI / 180)                 /**< PI division by 180 */
#define NMEA_EARTHRADIUS_KM         (6378)                          /**< Earth's mean radius in km */
#define NMEA_EARTHRADIUS_M          (NMEA_EARTHRADIUS_KM * 1000)    /**< Earth's mean radius in m */
#define NMEA_EARTH_SEMIMAJORAXIS_M  (6378137.0)                     /**< Earth's semi-major axis in m according WGS84 */
#define NMEA_EARTH_SEMIMAJORAXIS_KM (NMEA_EARTHMAJORAXIS_KM / 1000) /**< Earth's semi-major axis in km according WGS 84 */
#define NMEA_EARTH_FLATTENING       (1 / 298.257223563)             /**< Earth's flattening according WGS 84 */
#define NMEA_DOP_FACTOR             (5)                             /**< Factor for translating DOP to meters */

/*
 * degree VS radian
 */

double nmea_degree2radian(const double val);
double nmea_radian2degree(const double val);

/*
 * NDEG (NMEA degree)
 */

double nmea_ndeg2degree(const double val);
double nmea_degree2ndeg(const double val);

double nmea_ndeg2radian(const double val);
double nmea_radian2ndeg(const double val);

/*
 * DOP
 */

double nmea_calc_pdop(const double hdop, const double vdop);
double nmea_dop2meters(const double dop);
double nmea_meters2dop(const double meters);

/*
 * positions work
 */

void nmea_info2pos(const NmeaInfo *info, NmeaPosition *pos);
void nmea_pos2info(const NmeaPosition *pos, NmeaInfo *info);

double nmea_distance(const NmeaPosition *from_pos, const NmeaPosition *to_pos);

double nmea_distance_ellipsoid(const NmeaPosition *from_pos, const NmeaPosition *to_pos, double *from_azimuth,
    double *to_azimuth);

int nmea_move_horz(const NmeaPosition *start_pos, NmeaPosition *end_pos, double azimuth, double distance);

int nmea_move_horz_ellipsoid(const NmeaPosition *start_pos, NmeaPosition *end_pos, double azimuth, double distance,
    double *end_azimuth);

#ifdef  __cplusplus
}
#endif /* __cplusplus */

#endif /* __NMEALIB_GMATH_H__ */
