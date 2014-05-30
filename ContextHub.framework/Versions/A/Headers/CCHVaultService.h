//
//  CCHVaultService.h
//  ContextHub
//
//  Created by Kevin Lee on 10/7/13.
//  Copyright (c) 2013 ChaiOne. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CCHVaultItem.h"

#define kContextHubVaultErrorDomain @"com.contexthub.vault.error"
/** 
 ContextHub Vault error codes.
 */
typedef NS_ENUM(NSInteger, CCHVaultErrorCode) {
    /**
     missing container error code.
     */
    CCHMissingContainerCode = 0
};

typedef void (^vaultCompletionBlock)(NSDictionary *response, NSError *error);
typedef void (^vaultListingCompletionBlock)(NSArray *responses, NSError *error);

/**
 The shared CCHVaultSerivce should be used to persist data to the ContextHub Vault API.  This class provides methods for creating data in containers.
 You can think of a container as a bucket for common data.
 Once you persist data, you can retrieve it by Container and Id.
 */
@interface CCHVaultService : NSObject

/**
 @returns singleton instance of the the Vault Service
 */
+ (CCHVaultService *)sharedService;

/**
 Creates items in the ContextHub Vault.
 @param item the NSDictionary representation of the item you want to persist.
 @param containerName the name of the container that will be used to store similar data.
 @param attachments (optional) an array of CCHVaultResource objects.
 @param completion (optional) called when the request completes. The block is passed an NSDictionary representation of the item. If an error occurs, the NSError will be passed to the block.
 @note the dictionary that is returned will have a key name vault_info.  This object contains the id and other metadata that is used to work with the item on the ContextHub server.
 @note the name used in the CCHVaultResource will be added as a property on the item.  The property will contain the URL that you can use to download the file.
 */
- (void)createItem:(NSDictionary *)item inContainer:(NSString *)containerName withAttachments:(NSArray *)attachments completion:(vaultCompletionBlock)completion;

/**
 Gets an item from a container in the Vault.
 @param vaultId the vault id of the item.  The id is found in the key path @"vault_info.id".
 @param containerName the name of the container. the container name can be found in the key path @"vault_info.container"
 @param completion called when the request completes.
 */
- (void)getItemWithId:(NSString *)vaultId inContainer:(NSString *)containerName completion:(vaultCompletionBlock)completion;

/**
 Gets all items stored in a container in the Vault.
 @param containerName name of the container for the items.
 @param completion called when the request completes. The block is passed an NSArray of dictionaries that representation of the items.  If an error occurs, the NSError will be passed to the block.
 */
- (void)getItemsInContainer:(NSString *)containerName completion:(vaultListingCompletionBlock)completion;

/**
 Updates an item in the Vault.
 @param item to be updated.
 @param attachments (optional) an array of CCHVaultResource objects.
 @param completion (optional) called when the request completes. The block is passed an NSDictionary representation of the item. If an error occurs, the NSError will be passed to the block.
 @note the name used in the CCHVaultResource will be added as a property on the item.  The property will contain the URL that you can use to download the file.
 */
- (void)updateItem:(NSDictionary *)item withAttachments:(NSArray *)attachments completion:(vaultCompletionBlock)completion;

/**
 Deletes an item from the Vault.
 @param item item to be deleted;
 @param completion (optional) called when the request completes. If an error occurs, the NSError will be passed to the block.
 */
- (void)deleteItem:(NSDictionary *)item completion:(vaultCompletionBlock)completion;

@end
