/*
The MIT License (MIT)

Copyright (c) 2012-Present, Syoyo Fujita and many contributors.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

//
// version 2.0.0 : Add new object oriented API. 1.x API is still provided.
//                 * Add python binding.
//                 * Support line primitive.
//                 * Support points primitive.
//                 * Support multiple search path for .mtl(v1 API).
//                 * Support vertex skinning weight `vw`(as an tinyobj
//                 extension). Note that this differs vertex weight([w]
//                 component in `v` line)
//                 * Support escaped whitespece in mtllib
//                 * Add robust triangulation using Mapbox
//                 earcut(TINYOBJLOADER_USE_MAPBOX_EARCUT).
// version 1.4.0 : Modifed ParseTextureNameAndOption API
// version 1.3.1 : Make ParseTextureNameAndOption API public
// version 1.3.0 : Separate warning and error message(breaking API of LoadObj)
// version 1.2.3 : Added color space extension('-colorspace') to tex opts.
// version 1.2.2 : Parse multiple group names.
// version 1.2.1 : Added initial support for line('l') primitive(PR #178)
// version 1.2.0 : Hardened implementation(#175)
// version 1.1.1 : Support smoothing groups(#162)
// version 1.1.0 : Support parsing vertex color(#144)
// version 1.0.8 : Fix parsing `g` tag just after `usemtl`(#138)
// version 1.0.7 : Support multiple tex options(#126)
// version 1.0.6 : Add TINYOBJLOADER_USE_DOUBLE option(#124)
// version 1.0.5 : Ignore `Tr` when `d` exists in MTL(#43)
// version 1.0.4 : Support multiple filenames for 'mtllib'(#112)
// version 1.0.3 : Support parsing texture options(#85)
// version 1.0.2 : Improve parsing speed by about a factor of 2 for large
// files(#105)
// version 1.0.1 : Fixes a shape is lost if obj ends with a 'usemtl'(#104)
// version 1.0.0 : Change data structure. Change license from BSD to MIT.
//

//
// Use this in *one* .cc
//   #define TINYOBJLOADER_IMPLEMENTATION
//   #include "tiny_obj_loader.h"
//

#ifndef __OBJ_LOADER_HPP__
# define __OBJ_LOADER_HPP__

#include <map>
#include <string>
#include <vector>

namespace obj
{

typedef enum {
  TEXTURE_TYPE_NONE,  // default
  TEXTURE_TYPE_SPHERE,
  TEXTURE_TYPE_CUBE_TOP,
  TEXTURE_TYPE_CUBE_BOTTOM,
  TEXTURE_TYPE_CUBE_FRONT,
  TEXTURE_TYPE_CUBE_BACK,
  TEXTURE_TYPE_CUBE_LEFT,
  TEXTURE_TYPE_CUBE_RIGHT
} texture_type_t;

struct texture_option_t {
  texture_type_t type;      // -type (default TEXTURE_TYPE_NONE)
  float sharpness;         // -boost (default 1.0?)
  float brightness;        // base_value in -mm option (default 0)
  float contrast;          // gain_value in -mm option (default 1)
  float origin_offset[3];  // -o u [v [w]] (default 0 0 0)
  float scale[3];          // -s u [v [w]] (default 1 1 1)
  float turbulence[3];     // -t u [v [w]] (default 0 0 0)
  int texture_resolution;   // -texres resolution (No default value in the spec.
                            // We'll use -1)
  bool clamp;               // -clamp (default false)
  char imfchan;  // -imfchan (the default for bump is 'l' and for decal is 'm')
  bool blendu;   // -blendu (default on)
  bool blendv;   // -blendv (default on)
  float bump_multiplier;  // -bm (for bump maps only, default 1.0)

  // extension
  std::string colorspace;  // Explicitly specify color space of stored texel
                           // value. Usually `sRGB` or `linear` (default empty).
};

struct material_t {
  std::string name;

  float ambient[3];
  float diffuse[3];
  float specular[3];
  float transmittance[3];
  float emission[3];
  float shininess;
  float ior;       // index of refraction
  float dissolve;  // 1 == opaque; 0 == fully transparent
  // illumination model (see http://www.fileformat.info/format/material/)
  int illum;

  int dummy;  // Suppress padding warning.

  std::string ambient_texname;   // map_Ka. For ambient or ambient occlusion.
  std::string diffuse_texname;   // map_Kd
  std::string specular_texname;  // map_Ks
  std::string specular_highlight_texname;  // map_Ns
  std::string bump_texname;                // map_bump, map_Bump, bump
  std::string displacement_texname;        // disp
  std::string alpha_texname;               // map_d
  std::string reflection_texname;          // refl

  texture_option_t ambient_texopt;
  texture_option_t diffuse_texopt;
  texture_option_t specular_texopt;
  texture_option_t specular_highlight_texopt;
  texture_option_t bump_texopt;
  texture_option_t displacement_texopt;
  texture_option_t alpha_texopt;
  texture_option_t reflection_texopt;

  // PBR extension
  // http://exocortex.com/blog/extending_wavefront_mtl_to_support_pbr
  float roughness;            // [0, 1] default 0
  float metallic;             // [0, 1] default 0
  float sheen;                // [0, 1] default 0
  float clearcoat_thickness;  // [0, 1] default 0
  float clearcoat_roughness;  // [0, 1] default 0
  float anisotropy;           // aniso. [0, 1] default 0
  float anisotropy_rotation;  // anisor. [0, 1] default 0
  float pad0;
  std::string roughness_texname;  // map_Pr
  std::string metallic_texname;   // map_Pm
  std::string sheen_texname;      // map_Ps
  std::string emissive_texname;   // map_Ke
  std::string normal_texname;     // norm. For normal mapping.

  texture_option_t roughness_texopt;
  texture_option_t metallic_texopt;
  texture_option_t sheen_texopt;
  texture_option_t emissive_texopt;
  texture_option_t normal_texopt;

  int pad2;

  std::map<std::string, std::string> unknown_parameter;
};

struct tag_t {
  std::string name;

  std::vector<int> intValues;
  std::vector<float> floatValues;
  std::vector<std::string> stringValues;
};

struct joint_and_weight_t {
  int joint_id;
  float weight;
};

struct skin_weight_t {
  int vertex_id;  // Corresponding vertex index in `attrib_t::vertices`.
                  // Compared to `index_t`, this index must be positive and
                  // start with 0(does not allow relative indexing)
  std::vector<joint_and_weight_t> weightValues;
};

// Index struct to support different indices for vtx/normal/texcoord.
// -1 means not used.
struct index_t {
  int vertex_index;
  int normal_index;
  int texcoord_index;
};

struct mesh_t {
  std::vector<index_t> indices;
  std::vector<unsigned int>
      num_face_vertices;          // The number of vertices per
                                  // face. 3 = triangle, 4 = quad, ...
  std::vector<int> material_ids;  // per-face material ID
  std::vector<unsigned int> smoothing_group_ids;  // per-face smoothing group
                                                  // ID(0 = off. positive value
                                                  // = group id)
  std::vector<tag_t> tags;                        // SubD tag
};

// struct path_t {
//  std::vector<int> indices;  // pairs of indices for lines
//};

struct lines_t {
  // Linear flattened indices.
  std::vector<index_t> indices;        // indices for vertices(poly lines)
  std::vector<int> num_line_vertices;  // The number of vertices per line.
};

struct points_t {
  std::vector<index_t> indices;  // indices for points
};

struct shape_t {
  std::string name;
  mesh_t mesh;
  lines_t lines;
  points_t points;
};

// Vertex attributes
struct attrib_t {
  std::vector<float> vertices;  // 'v'(xyz)

  // For backward compatibility, we store vertex weight in separate array.
  std::vector<float> vertex_weights;  // 'v'(w)
  std::vector<float> normals;         // 'vn'
  std::vector<float> texcoords;       // 'vt'(uv)

  // For backward compatibility, we store texture coordinate 'w' in separate
  // array.
  std::vector<float> texcoord_ws;  // 'vt'(w)
  std::vector<float> colors;       // extension: vertex colors

  //
  // TinyObj extension.
  //

  // NOTE(syoyo): array index is based on the appearance order.
  // To get a corresponding skin weight for a specific vertex id `vid`,
  // Need to reconstruct a look up table: `skin_weight_t::vertex_id` == `vid`
  // (e.g. using std::map, std::unordered_map)
  std::vector<skin_weight_t> skin_weights;

  attrib_t() {}

  //
  // For pybind11
  //
  const std::vector<float> &GetVertices() const { return vertices; }

  const std::vector<float> &GetVertexWeights() const { return vertex_weights; }
};

struct callback_t {
  // W is optional and set to 1 if there is no `w` item in `v` line
  void (*vertex_cb)(void *user_data, float x, float y, float z, float w);
  void (*vertex_color_cb)(void *user_data, float x, float y, float z,
                          float r, float g, float b, bool has_color);
  void (*normal_cb)(void *user_data, float x, float y, float z);

  // y and z are optional and set to 0 if there is no `y` and/or `z` item(s) in
  // `vt` line.
  void (*texcoord_cb)(void *user_data, float x, float y, float z);

  // called per 'f' line. num_indices is the number of face indices(e.g. 3 for
  // triangle, 4 for quad)
  // 0 will be passed for undefined index in index_t members.
  void (*index_cb)(void *user_data, index_t *indices, int num_indices);
  // `name` material name, `material_id` = the array index of material_t[]. -1
  // if
  // a material not found in .mtl
  void (*usemtl_cb)(void *user_data, const char *name, int material_id);
  // `materials` = parsed material data.
  void (*mtllib_cb)(void *user_data, const material_t *materials,
                    int num_materials);
  // There may be multiple group names
  void (*group_cb)(void *user_data, const char **names, int num_names);
  void (*object_cb)(void *user_data, const char *name);

  callback_t()
      : vertex_cb(NULL),
        vertex_color_cb(NULL),
        normal_cb(NULL),
        texcoord_cb(NULL),
        index_cb(NULL),
        usemtl_cb(NULL),
        mtllib_cb(NULL),
        group_cb(NULL),
        object_cb(NULL) {}
};

class MaterialReader {
 public:
  MaterialReader() {}
  virtual ~MaterialReader();

  virtual bool operator()(const std::string &matId,
                          std::vector<material_t> *materials,
                          std::map<std::string, int> *matMap, std::string *warn,
                          std::string *err) = 0;
};

///
/// Read .mtl from a file.
///
class MaterialFileReader : public MaterialReader {
 public:
  // Path could contain separator(';' in Windows, ':' in Posix)
  explicit MaterialFileReader(const std::string &mtl_basedir)
      : m_mtlBaseDir(mtl_basedir) {}
  virtual ~MaterialFileReader() {}
  virtual bool operator()(const std::string &matId,
                          std::vector<material_t> *materials,
                          std::map<std::string, int> *matMap, std::string *warn,
                          std::string *err);

 private:
  std::string m_mtlBaseDir;
};

///
/// Read .mtl from a stream.
///
class MaterialStreamReader : public MaterialReader {
 public:
  explicit MaterialStreamReader(std::istream &inStream)
      : m_inStream(inStream) {}
  virtual ~MaterialStreamReader() {}
  virtual bool operator()(const std::string &matId,
                          std::vector<material_t> *materials,
                          std::map<std::string, int> *matMap, std::string *warn,
                          std::string *err);

 private:
  std::istream &m_inStream;
};

// v2 API
struct ObjReaderConfig {
  bool triangulate;  // triangulate polygon?

  // Currently not used.
  // "simple" or empty: Create triangle fan
  // "earcut": Use the algorithm based on Ear clipping
  std::string triangulation_method;

  /// Parse vertex color.
  /// If vertex color is not present, its filled with default value.
  /// false = no vertex color
  /// This will increase memory of parsed .obj
  bool vertex_color;

  ///
  /// Search path to .mtl file.
  /// Default = "" = search from the same directory of .obj file.
  /// Valid only when loading .obj from a file.
  ///
  std::string mtl_search_path;

  ObjReaderConfig()
      : triangulate(true), triangulation_method("simple"), vertex_color(true) {}
};

///
/// Wavefront .obj reader class(v2 API)
///
class ObjReader {
 public:
  ObjReader() : valid_(false) {}

  ///
  /// Load .obj and .mtl from a file.
  ///
  /// @param[in] filename wavefront .obj filename
  /// @param[in] config Reader configuration
  ///
  bool ParseFromFile(const std::string &filename,
                     const ObjReaderConfig &config = ObjReaderConfig());

  ///
  /// Parse .obj from a text string.
  /// Need to supply .mtl text string by `mtl_text`.
  /// This function ignores `mtllib` line in .obj text.
  ///
  /// @param[in] obj_text wavefront .obj filename
  /// @param[in] mtl_text wavefront .mtl filename
  /// @param[in] config Reader configuration
  ///
  bool ParseFromString(const std::string &obj_text, const std::string &mtl_text,
                       const ObjReaderConfig &config = ObjReaderConfig());

  ///
  /// .obj was loaded or parsed correctly.
  ///
  bool Valid() const { return valid_; }

  const attrib_t &GetAttrib() const { return attrib_; }

  const std::vector<shape_t> &GetShapes() const { return shapes_; }

  const std::vector<material_t> &GetMaterials() const { return materials_; }

  ///
  /// Warning message(may be filled after `Load` or `Parse`)
  ///
  const std::string &Warning() const { return warning_; }

  ///
  /// Error message(filled when `Load` or `Parse` failed)
  ///
  const std::string &Error() const { return error_; }

 private:
  bool valid_;

  attrib_t attrib_;
  std::vector<shape_t> shapes_;
  std::vector<material_t> materials_;

  std::string warning_;
  std::string error_;
};

/// ==>>========= Legacy v1 API =============================================

/// Loads .obj from a file.
/// 'attrib', 'shapes' and 'materials' will be filled with parsed shape data
/// 'shapes' will be filled with parsed shape data
/// Returns true when loading .obj become success.
/// Returns warning message into `warn`, and error message into `err`
/// 'mtl_basedir' is optional, and used for base directory for .mtl file.
/// In default(`NULL'), .mtl file is searched from an application's working
/// directory.
/// 'triangulate' is optional, and used whether triangulate polygon face in .obj
/// or not.
/// Option 'default_vcols_fallback' specifies whether vertex colors should
/// always be defined, even if no colors are given (fallback to white).
bool LoadObj(attrib_t *attrib, std::vector<shape_t> *shapes,
             std::vector<material_t> *materials, std::string *warn,
             std::string *err, const char *filename,
             const char *mtl_basedir = NULL, bool triangulate = true,
             bool default_vcols_fallback = true);

/// Loads .obj from a file with custom user callback.
/// .mtl is loaded as usual and parsed material_t data will be passed to
/// `callback.mtllib_cb`.
/// Returns true when loading .obj/.mtl become success.
/// Returns warning message into `warn`, and error message into `err`
/// See `examples/callback_api/` for how to use this function.
bool LoadObjWithCallback(std::istream &inStream, const callback_t &callback,
                         void *user_data = NULL,
                         MaterialReader *readMatFn = NULL,
                         std::string *warn = NULL, std::string *err = NULL);

/// Loads object from a std::istream, uses `readMatFn` to retrieve
/// std::istream for materials.
/// Returns true when loading .obj become success.
/// Returns warning and error message into `err`
bool LoadObj(attrib_t *attrib, std::vector<shape_t> *shapes,
             std::vector<material_t> *materials, std::string *warn,
             std::string *err, std::istream *inStream,
             MaterialReader *readMatFn = NULL, bool triangulate = true,
             bool default_vcols_fallback = true);

/// Loads materials into std::map
void LoadMtl(std::map<std::string, int> *material_map,
             std::vector<material_t> *materials, std::istream *inStream,
             std::string *warning, std::string *err);

///
/// Parse texture name and texture option for custom texture parameter through
/// material::unknown_parameter
///
/// @param[out] texname Parsed texture name
/// @param[out] texopt Parsed texopt
/// @param[in] linebuf Input string
///
bool ParseTextureNameAndOption(std::string *texname, texture_option_t *texopt,
                               const char *linebuf);

}


#endif
