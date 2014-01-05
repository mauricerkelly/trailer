
#define API_SERVER @"api.github.com"
#define TRAILER_GITHUB_REPO @"http://dev.housetrip.com/trailer/"
#define LOW_API_WARNING 0.10

typedef enum {
	kNewComment = 0,
	kNewPr = 1,
	kPrMerged = 2
} PRNotificationType;

typedef enum {
	kCreationDate = 0,
	kRecentActivity = 1,
	kTitle= 2
} PRSortingMethod;

#define PULL_REQUEST_ID_KEY @"pullRequestIdKey"
#define COMMENT_ID_KEY @"commentIdKey"
#define NOTIFICATION_URL_KEY @"urlKey"

#define RATE_UPDATE_NOTIFICATION @"RateUpdateNotification"

#define NETWORK_TIMEOUT 60.0

@interface API : NSObject

@property (nonatomic) NSString *authToken, *localUser, *localUserId, *resetDate;
@property (nonatomic) NSInteger sortMethod;
@property (nonatomic) float refreshPeriod, requestsLimit, requestsRemaining;
@property (nonatomic) Reachability *reachability;
@property (nonatomic) BOOL shouldHideUncommentedRequests, showCommentsEverywhere, sortDescending, showCreatedInsteadOfUpdated, dontKeepMyPrs, hideAvatars;

- (void)updateLimitFromServer;

- (void) fetchRepositoriesAndCallback:(void(^)(BOOL success))callback;

- (void) fetchPullRequestsForActiveReposAndCallback:(void(^)(BOOL success))callback;

- (void) getRateLimitAndCallback:(void(^)(long long remaining, long long limit, long long reset))callback;

- (NSOperation *)getImage:(NSString *)path
				  success:(void(^)(NSHTTPURLResponse *response, NSData *imageData))successCallback
				  failure:(void(^)(NSHTTPURLResponse *response, NSError *error))failureCallback;

@end
