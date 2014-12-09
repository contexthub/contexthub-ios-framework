## 1.4.1 - December 1, 2014

#### Tag Operator ####
GET API's have new methods that accept a Tag Operator.  The operator is used to build the query with the tags.  Passing ANY will find all geofences that match any of the tags. Passing ALL will find geofences that have all of the tags provided.  Passing nil will use the default ALL operator.
- CCHBeaconService: 
```objective-c
- (void)getBeaconsWithTags:(NSArray *)tags operator:(NSString *)tagOperator completionHandler:(void (^)(NSArray *beacons, NSError *error))completionHandler;
```
- CCHDevice: 
```objective-c
- (void)getDevicesWithTags:(NSArray *)tags operator:(NSString *)tagOperator completionHandler:(void(^)(NSArray *devices, NSError *error))completionHandler;
```
- CCHGeofenceService: 
```objective-c
- (void)getGeofencesWithTags:(NSArray *)tags operator:(NSString *)tagOperator location:(CLLocation *)location radius:(CLLocationDistance)radius completionHandler:(void(^)(NSArray *geofences, NSError *error))completionHandler;
```
- CCHVault: 
```
- (void)getItemsWithTags:(NSArray *)tags operator:(NSString *)tagOperator keyPath:(NSString *)keyPath value:(NSString *)value completionHandler:(vaultListingCompletionBlock)completionHandler;
```

#### Push ####
`CCHPush` supports the Unified Push service provided by the ContextHub API.  The following Keys are suported in the userInfo dictionary that is used in `CCHPush`.

| key   | value |
| ----- | ----- |
| alert | the message you want sent |
| sound | sound file you want played |
| content-available | pass in a 1 if you want to deliver a push in the background |
| badge | the number to be displayed on the icon |
| exclude_device_ids | an array of the device ids that should be excluded |
| exclude_push_tokens | an array of push tokens that should be excluded |
| mdm | mobile device management key |
| priority | can be either be set to 10 (immediate) or 5 (conserve power) |
| expiry | identifies when a notification is no longer valid and can be discarded.  The default is 1 day |
| category | category for push |
| url_args | sets the url arguments |
| collapse_key | used to group messages on the Google Cloud Messaging service |

**CCHPush Method Change**: the tag operator has been added to the send method. 

```objective-c
- (void)sendNotificationToTags:(NSArray *)tags operator:(NSString *)tagOperator userInfo:(NSDictionary *)userInfo completionHandler:(void (^)(NSError *error))completionHandler;
```


## 1.3.5 - November 4, 2014
- updated the way tags are querired.  Tags are now retrieved using an AND operator rather than an OR.  So if you have a resource that is tagged [a, b, c] and query for [a, c], it will return the resource.  If you query [a, d] it will not return the resource.
- added a new object `CCHContextHubPush` that is used when resource changes are pushed to the device
- CCHPush **method signature changed** Changed the signature of the completion handler in `application:didReceiveRemoteNotification:completionHandler:` from `(void (^) (enum UIBackgroundFetchResult result, BOOL CCHContextHubPush))` to `(void (^) (enum UIBackgroundFetchResult result, CCHContextHubPush contextHubPush))`  Note that it now passes the new CCHContextHubPush object to the completion handler.

## 1.3.4 - October 23, 2014
- fixed a bug in the way some iBeacons were handled.
- added CCHSubscriptionResourceChangeNotification.

## 1.3.3 - October 7, 2014
- Improvements to network performance
- updated the way nil tags and empty tags are processed.
- added `horizontal_accuracy` and `vertical_accuracy` to the location context dictionary.
- updated date format to `yyyy-MM-dd'T'HH:mm:ssZZZZZ`

## 1.3.2 - September 18, 2014
- iOS 8.0 tested.
- CCHPush - **Method signature changed**: added CCHContextHubPush boolean to remote notification handler.
- CCHSensorPipeline - added new delegate method `sensorPipeline:didDetectEvent`
- CCHSensorPipeline - **Method renamed**: renamed `addSubscriptionsForTags:`, `removeSubscriptionsForTags` to `addElementsWithTags:`, `removeElementsWithTags:`
- CCHDevice - **Method renamed**: renamed `updateDeviceAlias:tags:completionHandler` to `setDeviceAlias:tags:completionHandler`
- updated the structure of the `context` in the event dictionary.
- added optimizations to the way HTTP sessions are queued.
- updated the way geofences are reported in the location context.
- added `triggered_at` to the event dictionary.

## 1.2.0 - August 15, 2014
- **CCHSubscriptionService - Method Renamed** - renamed 'getSubscriptionsWithCompletion:' to 'getSubscriptionsWithCompletionHandler'
- CCHSubscriptionService - you can subscribe to device changes in and observe change notifications (CCHDeviceCreatedNotification, CCHDeviceUpdatedNotification, CCHDeviceDeletedNotification)
- CCHDevice - A new api for working with devices stored on the ContextHub server.

## 1.1.4 - July 31, 2014
- CCHSensorPipeline - changed method name `triggerEvent:completionHandler:`
- CCHVersion - allows you to check the version of the framework.

## 1.1.3 - July 15, 2014
- CCHSensorPipeline - you can trigger custom events
- CCHSubscriptions - improved the way you add and remove subscriptions
- CCHLog - new api for creating log statements on the ContextHub server

## 1.1.2 - July 11, 2014
- CCHVault - added ability to query vault items using key paths
- Bug Fix - background fetch completion handler is now executed for all resource actions (created, updated, deleted)

## 1.1.1 - June 30, 2014
- added docset
- updated documentation in header files

## 1.1.0 - June 30, 2014
- framework release
