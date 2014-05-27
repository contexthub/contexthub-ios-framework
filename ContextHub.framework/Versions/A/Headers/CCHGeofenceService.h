//
//  CCBGeofenceService.h
//  ContextHub
//
//  Created by Kevin Lee on 10/29/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>
#import "ContextHub.h"

/** 
 Used to get CLCircularRegions (geofences) from the ContextHub api.
 */
@interface CCHGeofenceService : CLCircularRegion

/**
 gets global geofences from ContextHub api.  Geofences without tags are considered global geofences.
 @param success executed when the network request completes without errors.  The success param is passed an array of CLCircularRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getGeofencesWithSuccess:(void(^)(NSArray *fences))success
                        failure:(void(^)(NSError *error))failure;

/**
 gets all geofences from ContextHub api.
 @param success executed when the network request completes without errors.  The success param is passed an array of CLCircularRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getAllGeofenceInfoWithSuccess:(void(^)(NSArray *fences))success
                        failure:(void(^)(NSError *error))failure;

/**
 get geofences from ContextHub api
 @param tag used to filter results.
 @param success executed when the network request completes without errors.  The success param is passed an array of CLCircularRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getGeofencesWithTag:(NSString *)tag success:(void(^)(NSArray *fences))success
                        failure:(void(^)(NSError *error))failure;

/**
 get geofences from ContextHub api
 @param location to be used to find the nearest geofences
 @param success executed when the network request completes without errors.  The success param is passed an array of CLCircularRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */

+ (void)getGeofencesNearLocation:(CLLocation *)location withSuccess:(void(^)(id responseObject))success
                         failure:(void(^)(NSError *error))failure;

/**
 get geofences from ContextHub api
 @param tag used to filter results.
 @param location to be used to find the nearest geofences.
 @param success executed when the network request completes without errors.  The success param is passed an array of CLCircularRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */

+ (void)getGeofencesWithTag:(NSString *)tag nearLocation:(CLLocation *)location withSuccess:(void(^)(id responseObject))success
                         failure:(void(^)(NSError *error))failure;


/**
 get geofences from ContextHub api that are near the current location.
 @param success executed when the network request completes without errors.  The success param is passed an array of CLCircularRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getGeofencesNearByWithSuccess:(void(^)(NSArray *geofences))success
                              failure:(void(^)(NSError *error))failure;

/**
 get geofences from ContextHub api that are near the current location.
 @param tag used to filter results
 @param success executed when the network request completes without errors.  The success param is passed an array of CLCircularRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getGeofencesNearByWithTag:(NSString *)tag success:(void(^)(NSArray *geofences))success
                              failure:(void(^)(NSError *error))failure;


/**
 get geofences from ContextHub api.  This method is used to retrive geofences so that they can be updated, or deleted.
 @param tag used to filter results.
 @param location to be used to find the nearest geofences.
 @param success executed when the network request completes without errors.  The success param is passed an array of NSDictionary objects that represent geofences.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */

+ (void)getGeofenceInfoWithTag:(NSString *)tag nearLocation:(CLLocation *)location withSuccess:(void(^)(id responseObject))success
                    failure:(void(^)(NSError *error))failure;



/**
 gets a geofence from ContextHub api
 @param geofenceId the ContextHub id for the geofence.
 @param success executed when the network request completes without errors.  The success param is passed an array of CLCircularRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getGeofenceInfoWithId:(NSString *)geofenceId success:(void(^)(NSDictionary *fenceInfo))success
                        failure:(void(^)(NSError *error))failure;

/**
used to create a geofence on the ContextHub server.
@param region geofence region
@param completion executed when the network request completes. If successful, a fence info dictionary will be returned.  If an error occurs, the NSError will be returned.
*/
+ (void)createGeofence:(CLCircularRegion *)region
            completion:(void(^)(NSDictionary *fenceInfo, NSError *error))completion;

/**
 used to create a tagged geofence on the ContextHub server.
 @param tags tags used to scope the geofence
 @param region geofence region
 @param completion executed when the network request completes. If successful, a fence info dictionary will be returned.  If an error occurs, the NSError will be returned.
 */
+ (void)createGeofence:(CLCircularRegion *)region
              withTags:(NSArray *)tags completion:(void(^)(NSDictionary *fenceInfo, NSError *error))completion;

/**
 used to delete a geofence on the ContextHub server.
 @param fenceInfo is a dictionary that must contain the fence id of the geofence that is to be deleted.
 @param completion executed when the network request completes. an error will be returned if there was a problem deleting the geofence.
 */
+ (void)deleteGeofence:(NSDictionary *)fenceInfo
            completion:(void(^)(NSError *error))completion;

/**
 used to update a geofence on the ContextHub server.
 @param fenceInfo is a dictionary that must contain the fence id of the geofence that is to updated.
 @param completion executed when the network request completes. an error will be returned if there was a problem deleting the geofence.
 */
+ (void)updateGeofence:(NSDictionary *)fenceInfo
            completion:(void(^)(NSDictionary *fenceInfo, NSError *error))completion;

+ (CLCircularRegion *)regionForFenceInfo:(NSDictionary *)fenceInfo;
@end
