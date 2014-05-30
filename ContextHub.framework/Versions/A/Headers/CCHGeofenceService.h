//
//  CCHGeofenceService.h
//  ContextHub
//
//  Created by Kevin Lee on 10/29/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import "ContextHub.h"

/** 
 The Geofence Service is used to work with the geofences api on ContextHub.
 */
@interface CCHGeofenceService : CLCircularRegion


/**
 Creates a new geofence on the ContextHub server.
 @param region CLCircularRegion to be added to ContextHub.
 @param tags (optional) used to scope the geofence.  If nil, a global geofence will be created.
 @param completion (optional) called when the request completes.  The block is passed an NSDictionary object that represents the geofence.  If an error occurs, the NSError wil be passed to the block.
 */
+ (void)createGeofence:(CLCircularRegion *)region
              withTags:(NSArray *)tags completion:(void(^)(NSDictionary *geofence, NSError *error))completion;

/**
 Gets a geofence from ContextHub using the geofence Id.
 @param geofenceId the ContextHub id for the geofence.
 @param completion called when the request completes. The block is passed an NSDictionary object that represents the geofence.  If an error occurs, the NSError wil be passed to the block.
 */
+ (void)getGeofenceWithId:(NSString *)geofenceId completion:(void(^)(NSDictionary *geofence, NSError *error))completion;

/**
 Gets geofences from ContextHub server.
 @param tag (optional) used to filter results.  Passing nil will return all geofences.  Passing CCHGlobalTag will return only global geofences.
 @param location (optional) to be used to filter the nearest geofences.  Passing nil will return all geofences.
 @param completion called when the request completes. The block is passed an NSArray of NSDictionary objects that represent geofences.  If an error occurs, the NSError will be passed to the block.
 */
+ (void)getGeofencesWithTag:(NSString *)tag nearLocation:(CLLocation *)location completion:(void(^)(NSArray *geofences, NSError *error))completion;

/**
 Updates a geofence on the ContextHub server.
 @param geofence to be updated on ContextHub.
 @param completion called when the request completes. If an error occurs, the NSError will be passed to the block.
 */
+ (void)updateGeofence:(NSDictionary *)geofence
            completion:(void(^)(BOOL success, NSError *error))completion;

/**
 Deletes an existing geofence from ContextHub.
 @param geofence to be deleted from ContextHub.
 @param completion called when the request completes. If an error occurs, the NSError will be passed to the block.
 */
+ (void)deleteGeofence:(NSDictionary *)geofence
            completion:(void(^)(NSError *error))completion;

/**
 Creates a CLCircularRegion from a geofence dictionary returned from ContextHub
 @param geofence NSDictionary that contains geofence information.
 @return CLCircularRegion from a geofence dictionary.
 */
+ (CLCircularRegion *)regionForGeofence:(NSDictionary *)geofence;
@end
