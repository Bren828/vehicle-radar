Language: **English** or [Russian](https://github.com/Bren828/vehicle-radar/blob/main/README.md)

# vehicle-radar
Упрощенное создание транспортных радаров, с возможностью редактирования и создания.

## Reference
* [Download](https://github.com/Bren828/vehicle-radar#download)
* [Installation](https://github.com/Bren828/vehicle-radar#installation)
* [Example](https://github.com/Bren828/vehicle-radar#example)
* [Callbacks](https://github.com/Bren828/vehicle-radar#callbacks)
* [Functions](https://github.com/Bren828/vehicle-radar#functions)
* [Definition](https://github.com/Bren828/vehicle-radar#definition)

## Download
[Releases page](https://github.com/Bren828/vehicle-radar/releases)

## Installation

Include in your code and begin using the library:
```pawn
#include <vehicle-radar>
```

## Example

```pawn
new radarid = VehicleRadarLoad(130, 50.0,  0.0, 0.0, 0.0,  0.0, 0.0, 0.0); // create a radar
SetVehicleRadarExtraValue(radarid, 1005); // add the value

public OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activation_count)
{
    printf("Enter Vehicle Radar | radarid: %d | vehicleid: %d | activation_count: %d", radarid, vehicleid, activation_count)
    return 1;
}

public OnPlayerVehicleRadarCreate(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
{
    printf("Create | radarid %d | speed_limit %d | zone_size %f | x %.2f | y %.2f | z %.2f | rx %.2f | ry %.2f | rz %.2f | worldid %d | int %d", 
        radarid, speed_limit, zone_size, x, y, z,  rx, ry,  rz,  worldid, interiorid
    );
    return 1;
}

public OnPlayerVehicleRadarEdit(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
{
    printf("Edit | radarid %d | speed_limit %d | zone_size %f | x %.2f | y %.2f | z %.2f | rx %.2f | ry %.2f | rz %.2f | worldid %d | int %d", 
        radarid, speed_limit, zone_size, x, y, z,  rx, ry,  rz,  worldid, interiorid
    );
    return 1;
}

public OnPlayerVehicleRadarDelete(playerid, radarid, extra_value)
{
    printf("Delete | radarid %d | extra_value %d", radarid, extra_value);
	    return 1;
}
```

## Callbacks
#### public OnPlayerEnterVehicleRadar(playerid, radarid, vehicleid, activation_count)
* Вызывается при создании нового радара
> * `playerid` - ID игрока
> * `radarid` - ID радара
> * `vehicleid` - ID транспорта
> * `activation_count` - количество срабатываний


#### public OnPlayerVehicleRadarCreate(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
> Вызывается при создании нового радара
> * `radarid` - ID радара
> * `speed_limit` - Ограничение скорости
> * `Float:zone_size` - Дистанция срабатывания
> * `bool:disabled` - состояние радара (false - включен | true - выключен)
> * `Float:x` - Координата x
> * `Float:y` - Координата y
> * `Float:z` - Координата z
> * `Float:rx` - Координата x вращение объекта
> * `Float:ry` - Координата y вращение объекта
> * `Float:rz` - Координата z вращение объекта
> * `worldid` - ID виртуального 
> * `interiorid` - ID интерьера 


#### public OnPlayerVehicleRadarEdit(playerid, radarid, speed_limit, Float:zone_size, bool:disabled, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid, interiorid)
> Вызывается при редактировании созданного радара
> * `radarid` - ID радара
> * `speed_limit` - Ограничение скорости
> * `Float:zone_size` - Дистанция срабатывания
> * `bool:disabled` - состояние радара (false - включен | true - выключен)
> * `Float:x` - Координата x
> * `Float:y` - Координата y
> * `Float:z` - Координата z
> * `Float:rx` - Координата x вращение объекта
> * `Float:ry` - Координата y вращение объекта
> * `Float:rz` - Координата z вращение объекта
> * `worldid` - ID виртуального 
> * `interiorid` - ID интерьера 


#### public OnPlayerVehicleRadarDelete(playerid, radarid, extra_value)
> Вызывается при удалении радара
> * `radarid` - ID радара
> * `extra_value` - дополнительное значение
> * ПРИМЕЧАНИЕ: `extra_value` устанавливается через `SetVehicleRadarExtraValue`. Эта свободная переменная которую можно использовать для хранения IDs базы MySQL


## Functions
#### VehicleRadarCreate(playerid)
> Создать радар
> * `playerid` - ID игрока


#### VehicleRadarList(playerid)
> Просмотреть список созданных радаров
> * `playerid` - ID игрока


#### VehicleRadarLoad(speed_limit, Float:zone_size, Float:x, Float:y, Float:z, Float:rx, Float:ry, Float:rz, worldid = -1, interiorid = -1, bool:disabled = false, const text3D[] = "-1", text3D_color = -1, Float:text3D_distance = VEHICLE_RADAR_3DTEXT_DISTANCE)
> Загрузить радар
> * `speed_limit` - Ограничение скорости
> * `Float:zone_size` - Дистанция срабатывания
> * `Float:x` - Координата x
> * `Float:y` - Координата y
> * `Float:z` - Координата z
> * `Float:rx` - Координата x вращение объекта
> * `Float:ry` - Координата y вращение объекта
> * `Float:rz` - Координата z вращение объекта
> * `worldid` - ID виртуального мира
> * `interiorid` - ID интерьера 
> * `bool:disabled` - Выключить радар (false - нет | true - да)
> * `const text3D[]` - 3DText
> * `text3D_color` - Цвет 3DText 
> * `Float:text3D_distance` - Дистанция отображения 3DText
> * Вернет: 0 при неудачи
> * Вернет: ID радара при успехе


#### DeleteVehicleRadar(playerid, radarid, bool:callback = true)
> Удалить радар
> * `radarid` - ID радара
> * `callback` - Вызвать 'OnPlayerVehicleRadarDelete' при удаление
> * Вернет: 0 при неудачи
> * Вернет: 1 при успехе


#### SetVehicleRadarActivationCount(radarid, count)
> Изменить количество срабатываний
> * `radarid` - ID радара
> * `count` - количество
> * Вернет: 0 при неудачи
> * Вернет: 1 при успехе


#### GetVehicleRadarActivationCount(radarid)
> Узнать количество срабатываний
> * `radarid` - ID радара
> * Вернет: 0 при неудачи
> * Вернет: количество срабатываний


#### SetVehicleRadarSpeedLimit(radarid, speed)
> Изменить ограничение скорости
> * `radarid` - ID радара
> * `speed` - скорость км/ч
> * Вернет: 0 при неудачи
> * Вернет: 1 при успехе


#### GetVehicleRadarSpeedLimit(radarid)
> Узнать ограничение скорости
> * `radarid` - ID радара
> * Вернет: 0 при неудачи
> * Вернет: текущую скорость


#### SetVehicleRadarZoneSize(radarid, Float:zone_size)
> Изменить дистанцию срабатывания
> * `radarid` - ID радара
> * `Float:zone_size` - дистанция
> * Вернет: 0 при неудачи
> * Вернет: 1 при успехе


#### GetVehicleRadarZoneSize(radarid, &Float:zone_size)
> Узнать дистанцию срабатывания
> * `radarid` - ID радара
> * `&Float:zone_size` - текущая дистанция
> * Вернет: 0 при неудачи
> * Вернет: 1 при успехе


#### SetVehicleRadarText(radarid, const text[], color, Float:drawdistance = VEHICLE_RADAR_3DTEXT_DISTANCE, Float:x = 0.0, Float:y = 0.0, Float:z = 0.0)
> Изменить 3D Text
> * `radarid` - ID радара
> * `text[]` - текст
> * `color` - цвет
> * `Float:drawdistance` - дистанция
> * `Float:x` - Координата x
> * `Float:y` - Координата y
> * `Float:z` - Координата z
> * Вернет: 0 при неудачи
> * Вернет: 1 при успехе


#### SetVehicleRadarExtraValue(radarid, value)
> Изменить дополнительное значение
> * `radarid` - ID радара
> * `value` - значение
> * Вернет: 0 при неудачи
> * Вернет: 1 при успехе
> * ПРИМЕЧАНИЕ: Эта свободная переменная которую можно использовать для хранения IDs базы MySQL


#### GetVehicleRadarExtraValue(radarid)
> Узнать дополнительное значение
> * `radarid` - ID радара
> * Вернет: 0 при неудачи
> * Вернет: текущие значение
> * ПРИМЕЧАНИЕ: Эта свободная переменная которую можно использовать для хранения IDs базы MySQL


## Definition
```pawn
#define MAX_VEHICLE_RADAR                   200

#define VEHICLE_RADAR_OBJECT_MODEL          18880 // модель объекта

#define VEHICLE_RADAR_OBJECT_DISTANCE       200.0 // истанция прорисовки объекта

#define VEHICLE_RADAR_3DTEXT_LENGTH   	    144	// Длина 3d текста

#define VEHICLE_RADAR_3DTEXT_TEXT  	        "Радар скорости №%d\nОграничение скорости: %d (км/ч)" // текст при '-1'

#define VEHICLE_RADAR_3DTEXT_DISTANCE       15.0 // дистанция прорисовки 3d текста

#define VEHICLE_RADAR_MAX_PAGES_LIST        20 // максимальное количество строчек в диалоге 

#define VEHICLE_RADAR_USE_EDITING_TOOLS  	  true //использовать инструменты редактирования
```
