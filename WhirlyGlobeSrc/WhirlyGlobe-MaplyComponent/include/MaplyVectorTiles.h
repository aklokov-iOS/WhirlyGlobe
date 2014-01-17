/*
 *  MaplyVectorTiles.h
 *  WhirlyGlobe-MaplyComponent
 *
 *  Created by Steve Gifford on 1/3/14.
 *  Copyright 2011-2014 mousebird consulting
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import <UIKit/UIKit.h>
#import "MaplyQuadPagingLayer.h"

@interface MaplyVectorTiles : NSObject<MaplyPagingDelegate>

- (id)initWithDirectory:(NSString *)tilesDir;
- (id)initWithDatabase:(NSString *)tilesDB;

@property (nonatomic,readonly) NSString *tilesDir;
@property (nonatomic,readonly) int minLevel;
@property (nonatomic,readonly) int maxLevel;

@property (nonatomic,readonly) NSArray *layerNames;

@property (nonatomic,readonly) NSArray *styles;

@end

@interface MaplyVectorTileStyle : NSObject

- (NSArray *)buildObjects:(NSArray *)vecObjs viewC:(MaplyBaseViewController *)viewC;

@property (nonatomic) bool geomAdditive;

@end

@interface MaplyVectorTileStyleLine : MaplyVectorTileStyle

- (id)initWithStyleEntry:(NSDictionary *)styleEntry index:(int)index;

@end

@interface MaplyVectorTileStylePolygon : MaplyVectorTileStyle

- (id)initWithStyleEntry:(NSDictionary *)styleEntry index:(int)index;

@end

@interface MaplyVectorTileStyleText : MaplyVectorTileStyle

- (id)initWithStyleEntry:(NSDictionary *)styleEntry index:(int)index;

@end

@interface MaplyVectorTileStyleMarker : MaplyVectorTileStyle

- (id)initWithStyleEntry:(NSDictionary *)styleEntry index:(int)index;

@end