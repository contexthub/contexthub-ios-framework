## 1.3.4 - October 23, 2014
- fixed a bug in the way some iBeacons were handled.
- added CCHSubscriptionResourceChangeNotification.

## 1.3.3 - October 7, 2014
- Improvements to network performance
- Updated the way nil tags and empty tags are processed.
- added `horizontal_accuracy` and `vertical_accuracy` to the location context dictionary.
- updated date format to `yyyy-MM-dd'T'HH:mm:ssZZZZZ`

## 1.3.2 - September 18, 2014
- iOS 8.0 tested.
- CCHPush - **Method signature changed**: added CCHContextHubPush boolean to remote notification handler.
- CCHSensorPipeline - added new delegate method `sensorPipeline:didDetectEvent`
- CCHSensorPipeline - **Method renamed**: renamed `addSubscriptionsForTags:`, `removeSubscriptionsForTags` to `addElementsWithTags:`, `removeElementsWithTags:`
- CCHDevice - **Method renamed**: renamed `updateDeviceAlias:tags:completionHandler` to `setDeviceAlias:tags:completionHandler`
- Updated the structure of the `context` in the event dictionary.
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
