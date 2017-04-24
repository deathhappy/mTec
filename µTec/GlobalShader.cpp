// Copyright (c) <2017> Michael Mroz
// This file is subject to the MIT License as seen in the root of this folder structure (LICENSE.TXT)
#include "GlobalShader.h"

using namespace �Tec;


void RayMarchingComputeShader::SetVP(const glm::mat4& WVP)
{
	glUniformMatrix4fv(gVPLocation, 1, GL_FALSE, &WVP[0][0]);
}

void �Tec::RayMarchingComputeShader::SetTime(const glm::vec4& t)
{
	glUniform4f(time, t.x, t.y, t.z, t.w);
}

void �Tec::RayMarchingComputeShader::SetObjectLength(const int& len)
{
	glUniform1i(objLength, len);
}

void �Tec::RayMarchingComputeShader::ToggleEffects(const glm::vec4& eff)
{
	glUniform4f(effectToggle, eff.x, eff.y, eff.z, eff.w);
}


void �Tec::RayMarchingComputeShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

NullShader::NullShader(void) : BaseShader("nullVs.shader", "nullFs.shader")
{
	bindUniforms();
}

NullShader::~NullShader( void )
{

}

void NullShader::bindUniforms()
{
	activate();
	gWVPLocation = glGetUniformLocation(shaderID, "gWVP");
}

void NullShader::SetWVP( const glm::mat4& WVP )
{
	glUniformMatrix4fv(gWVPLocation, 1, GL_FALSE, &WVP[0][0]);
}



FXAAShader::FXAAShader(void) : BaseShader("fxaaVs.shader","fxaaFs.shader")
{
	bindUniforms();
}


FXAAShader::~FXAAShader(void)
{
}

void FXAAShader::bindUniforms()
{
	activate();
	Texture0 = glGetUniformLocation(shaderID, "textureSampler");
	gWVPLocation = glGetUniformLocation(shaderID, "gWVP");
}

void FXAAShader::SetWVP( const glm::mat4& WVP )
{
	glUniformMatrix4fv(gWVPLocation, 1, GL_FALSE, &WVP[0][0]);
}

�Tec::ShadingShader::ShadingShader(void) : BaseShader("defaultVs.shader", "shadingFs.shader")
{
	bindUniforms();
}

�Tec::ShadingShader::~ShadingShader(void)
{
	
}

void �Tec::ShadingShader::SetVP(const glm::mat4& WVP)
{
	glUniformMatrix4fv(gVPLocation, 1, GL_FALSE, &WVP[0][0]);
}

void �Tec::ShadingShader::bindUniforms()
{
	activate();
	positions = glGetUniformLocation(shaderID, "positions");
	normals = glGetUniformLocation(shaderID, "normals");
	thick = glGetUniformLocation(shaderID, "thick");
	ids = glGetUniformLocation(shaderID, "ids");
	shadows = glGetUniformLocation(shaderID, "shadows");
	ao = glGetUniformLocation(shaderID, "ao");
	sss = glGetUniformLocation(shaderID, "sss");
	gVPLocation = glGetUniformLocation(shaderID, "gVP");
	reflections = glGetUniformLocation(shaderID, "reflections");
}

void �Tec::AoComputeShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

void �Tec::AoComputeShader::SetVP(const glm::mat4& WVP)
{
	glUniformMatrix4fv(gVPLocation, 1, GL_FALSE, &WVP[0][0]);
}

void �Tec::SssComputeShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

void �Tec::SssComputeShader::SetVP(const glm::mat4& WVP)
{
	glUniformMatrix4fv(gVPLocation, 1, GL_FALSE, &WVP[0][0]);
}

void �Tec::FieldCullingComputeShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

void �Tec::FieldCullingComputeShader::SetConeAngles(const glm::vec3& angles)
{
	glUniform3f(coneAngle, angles.x, angles.y, angles.z);
}

void �Tec::AoFieldCullingShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

void �Tec::ShadowsComputeShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

void �Tec::UpsamplingShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

�Tec::ReprojectionShader::ReprojectionShader(void) : BaseShader("defaultVs.shader", "reprojectionFs.shader")
{
	bindUniforms();
}

�Tec::ReprojectionShader::~ReprojectionShader(void)
{

}

void �Tec::ReprojectionShader::SetVP(const glm::mat4& WVP)
{
	glUniformMatrix4fv(gVPLocation, 1, GL_FALSE, &WVP[0][0]);
}

void �Tec::ReprojectionShader::bindUniforms()
{
	activate();
	frame = glGetUniformLocation(shaderID, "frame");
	pastHistory = glGetUniformLocation(shaderID, "pastHistory");
	newHistory = glGetUniformLocation(shaderID, "newHistory");
	gVPLocation = glGetUniformLocation(shaderID, "gVP");
	positions = glGetUniformLocation(shaderID, "positions");
	velocity = glGetUniformLocation(shaderID, "velocity");
}

void �Tec::VelocityComputeShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

void �Tec::VelocityComputeShader::SetHistoryVP(const glm::mat4& VP)
{
	glUniformMatrix4fv(historyVP, 1, GL_FALSE, &VP[0][0]);
}

void �Tec::ShadowFieldCullingShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

void �Tec::WorldSdfShader::SetGroups(const glm::ivec3 size)
{
	dispatchSize = size;
	glUniform3i(totalGroups, size.x, size.y, size.z);
}

void �Tec::WorldSdfShader::SetOffset(const glm::ivec3 size)
{
	glUniform3i(offset, size.x, size.y, size.z);
}

void �Tec::WorldIdShader::SetGroups(const glm::ivec3 size)
{
	dispatchSize = size;
	glUniform3i(totalGroups, size.x, size.y, size.z);
}

void �Tec::WorldIdShader::SetOffset(const glm::ivec3 size)
{
	glUniform3i(offset, size.x, size.y, size.z);
}

�Tec::BlockMarchingShader::BlockMarchingShader(void) : BaseShader("baseVs.shader", "blockMarchingFs.shader")
{
	bindUniforms();
}

�Tec::BlockMarchingShader::~BlockMarchingShader(void)
{

}

void �Tec::BlockMarchingShader::SetVP(const glm::mat4& VP)
{
	glUniformMatrix4fv(gVPLocation, 1, GL_FALSE, &VP[0][0]);
}

void �Tec::BlockMarchingShader::SetWorld(const glm::mat4& W)
{
	glUniformMatrix4fv(wLocation, 1, GL_FALSE, &W[0][0]);
}

void �Tec::BlockMarchingShader::SetInverseWorld(const glm::mat4& W)
{
	glUniformMatrix4fv(invWorld, 1, GL_FALSE, &W[0][0]);
}

void �Tec::BlockMarchingShader::SetIndex(int id)
{
	glUniform1i(index, id);
}

void �Tec::BlockMarchingShader::SetSDF(GLuint64 handle)
{
	glUniformHandleui64ARB(field, handle);
}

void �Tec::BlockMarchingShader::bindUniforms()
{
	activate();
	gVPLocation = glGetUniformLocation(shaderID, "gVP");
	wLocation = glGetUniformLocation(shaderID, "gWorld");
	index = glGetUniformLocation(shaderID, "index");
	field = glGetUniformLocation(shaderID, "field");
	invWorld = glGetUniformLocation(shaderID, "invWorld");
}

�Tec::ImplicitBlockMarchingShader::ImplicitBlockMarchingShader(void) : BaseShader("defaultVs.shader", "implicitBlockMarchingFs.shader")
{
	bindUniforms();
}

�Tec::ImplicitBlockMarchingShader::~ImplicitBlockMarchingShader(void)
{

}

void �Tec::ImplicitBlockMarchingShader::SetVP(const glm::mat4& VP)
{
	glUniformMatrix4fv(gVPLocation, 1, GL_FALSE, &VP[0][0]);
}

void �Tec::ImplicitBlockMarchingShader::SetIndex(int id)
{
	glUniform1i(index, id);
}

void �Tec::ImplicitBlockMarchingShader::bindUniforms()
{
	activate();
	gVPLocation = glGetUniformLocation(shaderID, "gVP");
	index = glGetUniformLocation(shaderID, "index");
}

void �Tec::ReflectionComputeShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}

void �Tec::BlurShader::SetRenderDimensions(const glm::vec2 eff)
{
	glUniform2f(renderDimensions, eff.x, eff.y);
}
