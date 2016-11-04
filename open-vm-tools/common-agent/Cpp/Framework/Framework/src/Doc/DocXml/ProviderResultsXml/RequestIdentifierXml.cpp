/*
 *  Author: bwilliams
 *  Created: April 6, 2012
 *
 *  Copyright (C) 2012-2016 VMware, Inc.  All rights reserved. -- VMware Confidential
 *
 *  This code was generated by the script "build/dev/codeGen/genCppXml". Please
 *  speak to Brian W. before modifying it by hand.
 *
 */

#include "stdafx.h"

#include "Doc/DocXml/SchemaTypesXml/ActionClassXml.h"

#include "Doc/ProviderResultsDoc/CRequestIdentifierDoc.h"
#include "Doc/SchemaTypesDoc/CActionClassDoc.h"
#include "Xml/XmlUtils/CXmlElement.h"
#include "Doc/DocXml/ProviderResultsXml/RequestIdentifierXml.h"

using namespace Caf;

void RequestIdentifierXml::add(
	const SmartPtrCRequestIdentifierDoc requestIdentifierDoc,
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("RequestIdentifierXml", "add");

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(requestIdentifierDoc);
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string clientIdVal =
			BasePlatform::UuidToString(requestIdentifierDoc->getClientId());
		CAF_CM_VALIDATE_STRING(clientIdVal);
		thisXml->addAttribute("clientId", clientIdVal);

		const std::string requestIdVal =
			BasePlatform::UuidToString(requestIdentifierDoc->getRequestId());
		CAF_CM_VALIDATE_STRING(requestIdVal);
		thisXml->addAttribute("requestId", requestIdVal);

		const std::string pmeIdVal = requestIdentifierDoc->getPmeId();
		CAF_CM_VALIDATE_STRING(pmeIdVal);
		thisXml->addAttribute("pmeId", pmeIdVal);

		const std::string jobIdVal =
			BasePlatform::UuidToString(requestIdentifierDoc->getJobId());
		CAF_CM_VALIDATE_STRING(jobIdVal);
		thisXml->addAttribute("jobId", jobIdVal);

		const SmartPtrCActionClassDoc actionClassVal =
			requestIdentifierDoc->getActionClass();
		CAF_CM_VALIDATE_SMARTPTR(actionClassVal);

		const SmartPtrCXmlElement actionClassXml =
			thisXml->createAndAddElement("actionClass");
		ActionClassXml::add(actionClassVal, actionClassXml);

		const std::string sessionIdVal =
			BasePlatform::UuidToString(requestIdentifierDoc->getSessionId());
		if (! sessionIdVal.empty()) {
			thisXml->addAttribute("sessionId", sessionIdVal);
		}

		thisXml->addAttribute("version", "1.0");
	}
	CAF_CM_EXIT;
}

SmartPtrCRequestIdentifierDoc RequestIdentifierXml::parse(
	const SmartPtrCXmlElement thisXml) {
	CAF_CM_STATIC_FUNC_VALIDATE("RequestIdentifierXml", "parse");

	SmartPtrCRequestIdentifierDoc requestIdentifierDoc;

	CAF_CM_ENTER {
		CAF_CM_VALIDATE_SMARTPTR(thisXml);

		const std::string clientIdStrVal =
			thisXml->findRequiredAttribute("clientId");
		UUID clientIdVal = CAFCOMMON_GUID_NULL;
		if (! clientIdStrVal.empty()) {
			BasePlatform::UuidFromString(clientIdStrVal.c_str(), clientIdVal);
		}

		const std::string requestIdStrVal =
			thisXml->findRequiredAttribute("requestId");
		UUID requestIdVal = CAFCOMMON_GUID_NULL;
		if (! requestIdStrVal.empty()) {
			BasePlatform::UuidFromString(requestIdStrVal.c_str(), requestIdVal);
		}

		const std::string pmeIdVal =
			thisXml->findRequiredAttribute("pmeId");

		const std::string jobIdStrVal =
			thisXml->findRequiredAttribute("jobId");
		UUID jobIdVal = CAFCOMMON_GUID_NULL;
		if (! jobIdStrVal.empty()) {
			BasePlatform::UuidFromString(jobIdStrVal.c_str(), jobIdVal);
		}

		const SmartPtrCXmlElement actionClassXml =
			thisXml->findRequiredChild("actionClass");

		SmartPtrCActionClassDoc actionClassVal;
		if (! actionClassXml.IsNull()) {
			actionClassVal = ActionClassXml::parse(actionClassXml);
		}

		const std::string sessionIdStrVal =
			thisXml->findOptionalAttribute("sessionId");
		UUID sessionIdVal = CAFCOMMON_GUID_NULL;
		if (! sessionIdStrVal.empty()) {
			BasePlatform::UuidFromString(sessionIdStrVal.c_str(), sessionIdVal);
		}

		requestIdentifierDoc.CreateInstance();
		requestIdentifierDoc->initialize(
			clientIdVal,
			requestIdVal,
			pmeIdVal,
			jobIdVal,
			actionClassVal,
			sessionIdVal);
	}
	CAF_CM_EXIT;

	return requestIdentifierDoc;
}
