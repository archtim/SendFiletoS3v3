// SendFiletoS3v3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "AwsBucket.h"

int main()
{
    const Aws::String bucket_name = "my-bucket";
    const Aws::String object_key = "famous-ace-pilot.jpg";
    const Aws::String file_name = "Images/famous-ace-pilot.jpg";

    // Note: the AWS region is specified in the CAwsBucket constructor
    CAwsBucket AwsClient;
    int ret = AwsClient.Send(bucket_name, file_name, object_key);
    return ret;
}
