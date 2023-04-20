#pragma once

#include <aws/core/Aws.h>
#include <aws/s3/S3Client.h>
#include <aws/s3/model/PutObjectRequest.h>
#include <fstream>
#include <Windows.h>

class CAwsBucket
{
private:
	Aws::SDKOptions options;
	Aws::Client::ClientConfiguration config;

public:
	CAwsBucket();
	~CAwsBucket();
	int Send(const Aws::String bucket_name, const Aws::String file_name, const Aws::String object_key);
};

