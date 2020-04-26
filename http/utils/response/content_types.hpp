//
// Created by Mark Vass on 2020. 04. 25..
//

#ifndef HTTP_CONTENT_TYPES_HPP
#define HTTP_CONTENT_TYPES_HPP

namespace http::utils::response {

struct content_types {
    enum application {
        JAVA_ARCHIVE,
        EDI_X12,
        EDIFACT,
        JAVASCRIPT,
        OCTET_STREAM,
        OGG,
        PDF,
        XHTML_XML,
        X_SHOCKWAVE_FLASH,
        JSON,
        LD_JSON,
        APPLICATION_XML,
        ZIP,
        X_WWW_FORM_URL_URLENCODED
    };
    enum audio {
        AUDIO_MPEG,
        X_MS_WMA,
        VND_RN_REALAUDIO,
        X_WAV
    };
    enum image {
        GIF,
        JPEG,
        PNG,
        TIFF,
        VND_MICROSOFT_ICON,
        X_ICON,
        VND_DJVU,
        SVG_XML
    };
    enum multipart {
        MIXED,
        ALTERNATIVE,
        RELATED,
        FORM_DATA
    };
    enum text {
        CSS,
        CSV,
        HTML,
        JAVASCRIPT_OBSOLETE,
        PLAIN,
        TEXT_XML
    };
    enum video {
        VIDEO_MPEG,
        MP4,
        QUICKTIME,
        X_MS_WMV,
        X_MSVIDEO,
        X_FLV,
        WEBM
    };
    enum vnd {
        APPLICATION_VND_ANDROID_PACKAGE_ARCHIVE,
        APPLICATION_VND_OASIS_OPENDOCUMENT_TEXT,
        APPLICATION_VND_OASIS_OPENDOCUMENT_SPREADSHEET,
        APPLICATION_VND_OASIS_OPENDOCUMENT_PRESENTATION,
        APPLICATION_VND_OASIS_OPENDOCUMENT_GRAPHICS,
        APPLICATION_VND_MS_EXCEL,
        APPLICATION_VND_OPENXMLFORMATS_OFFICEDOOCUMENT_SPREADSHEETML_SHEET,
        APPLICATION_VND_MS_POWERPOINT,
        APPLICATION_VND_OPENXMLFORMATS_OFFICEDOCUMENT_PRESENTATIONML_PRESENTATION,
        APPLICATION_VND_MSWORD,
        APPLICATION_VND_OPENCMLFORMATAS_OFFICEDOCUMENT_WORDPROCESSINGML_DOCUMENT,
        APPLICATION_VND_MOZILLA_XUL_XML
    };
};

}

#endif //HTTP_CONTENT_TYPES_HPP
