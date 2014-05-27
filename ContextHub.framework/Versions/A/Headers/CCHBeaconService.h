//
//  CCBBeaconService.h
//  ContextHub
//
//  Created by Kevin Lee on 11/7/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

/**
 The beacon servers is used to retrive iBeacons that have been created on the ContextHub server.
 */
@interface CCHBeaconService : NSObject
/**
 This method will return Global beacons.  Beacons without tags are considered global beacons.
 @param success executed when the network request completes without errors.  The success param is passed an array of NSDictionary objects that represent iBeacons.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getBeaconsWithSuccess:(void(^)(NSArray *beacons))success
                      failure:(void(^)(NSError *error))failure;

/**
 The method we return all beacons.
 @param success executed when the network request completes without errors.  The success param is passed an array of NSDictionary objects that represent iBeacons.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getAllBeaconsWithSuccess:(void(^)(NSArray *beacons))success
                         failure:(void(^)(NSError *error))failure;

/**
 @param beaconId id of the iBeacon stored in ContextHub
 @param success executed when the network request completes without errors.  The success param is passed an array of NSDictionary objects that represent iBeacons.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getBeaconInfoWithId:(NSString *)beaconId success:(void(^)(NSDictionary *beaconInfo))success
                      failure:(void(^)(NSError *error))failure;

/**
 This method will return Global beacons.  Beacons without tags are considered global beacons.
 @param success executed when the network request completes without errors.  The success param is passed an array of CLBeaconRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getBeaconRegionsWithSuccess:(void(^)(NSArray *beacons))success
                            failure:(void(^)(NSError *error))failure;


/**
 @param tag to be used in the request.
 @param success executed when the network request completes without errors.  The success param is passed an array of NSDictionary objects that represent iBeacons.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */

+ (void)getBeaconsWithTag:(NSString *)tag success:(void(^)(NSArray *beacons))success
                   failure:(void(^)(NSError *error))failure;

/**
 @param tag to be used in the request.
 @param success executed when the network request completes without errors.  The success param is passed an array of CLBeaconRegions.
 @param failure executed when the network request fails.  The session and error are passed to the failure block.
 */
+ (void)getBeaconRegionsWithTag:(NSString *)tag success:(void(^)(NSArray *beacons))success
                         failure:(void(^)(NSError *error))failure;
/**
 Create a new beacon in context hub.
 @param beaconRegion beacon to be added to context hub.
 @param completion called when the network request completes.
 */
+ (void)createBeacon:(CLBeaconRegion *)beaconRegion withCompletion:(void(^)(BOOL successful, NSError *error))completion;

/**
 Create a new beacon in context hub with tags.
 @param beaconRegion beacon to be added to context hub.
 @param tags NSArray of tags that will be used to retrieve the beacon
 @param completion called when the network request completes.
 */
+ (void)createBeacon:(CLBeaconRegion *)beaconRegion withTags:(NSArray *)tags withCompletion:(void(^)(BOOL successful, NSError *error))completion;

/**
 Update an existing beacon in context hub.
 @param beaconInfo beacon to be added to context hub.
 @param completion called when the network request completes.
 */
+ (void)updateBeacon:(NSDictionary *)beaconInfo withCompletion:(void(^)(BOOL successful, NSError *error))completion;

/**
 Delete an existing beacon in context hub.
 @param beaconInfo beacon to be added to context hub.
 @param completion called when the network request completes.
 */
+ (void)deleteBeacon:(NSDictionary *)beaconInfo withCompletion:(void(^)(BOOL successful, NSError *error))completion;

/**
 Creates a CLBeaconRegion from the beaconInfo object returned from ContextHub
 @param beaconInfo NSDictionary that contains beacon information.
 @return CLBeaconRegion that is build using the beaconInfo parmeter.
 */
+ (CLBeaconRegion *)regionForBeaconInfo:(NSDictionary *)beaconInfo;


@end
