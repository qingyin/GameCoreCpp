/****************************************************************************
Copyright (c) 2008-2010 Ricardo Quesada
Copyright (c) 2010-2012 cocos2d-x.org
Copyright (c) 2011      Zynga Inc.
Copyright (c) 2013-2014 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

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
****************************************************************************/
package org.cocos2dx.cpp;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxHelper;

import android.content.ClipData;
import android.content.ClipboardManager;
import android.content.pm.PackageInfo;
import android.os.Bundle;
import android.util.AndroidException;
import android.view.WindowManager;

public class AppActivity extends Cocos2dxActivity 
//public class AppActivity extends Cocos2dxHelper 
{
	public static native void NativeFunShowText(String text);
	
	private static AppActivity appActivity = null;
    //���а��������
    private static ClipboardManager mClipboardManager;
    //���а�Data����
    private static ClipData mClipData;
	@Override
	protected void onCreate(Bundle savedInstanceState) 
	{
		super.onCreate(savedInstanceState);
		appActivity = this;
		getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
		mClipboardManager = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);
	}
	
	public static String getAppVersion() throws AndroidException
	{
		PackageInfo pInfo = getContext().getPackageManager().getPackageInfo(getContext().getPackageName(), 0);
		String version = pInfo.versionName +" "+ pInfo.versionCode;
		return version;
	}
	public static boolean copyText(String copyTxt)
	{
        //����һ���µ��ı�clip����
        mClipData = ClipData.newPlainText("Simple test", copyTxt);
		//��clip������ڼ�������
        mClipboardManager.setPrimaryClip(mClipData);
        return true;
	}
	public static String getTestAllString(boolean b,int i,float f,double d,String s)
	{
		final String str = "bool:"+ b + " int:" + i + " float:" + f + " double:" + d + " String:" + s;
		System.out.println("----getTestAll----out runOnUiThread-----"+str);
		appActivity.runOnUiThread(new Runnable(){
			public void run(){
				System.out.println("----getTestAll----in runOnUiThread-----"+str);				
			}
		});
		return str;
	}
	public static void callNativeFunShowText(boolean b,int i,float f,double d,String s)
	{
		final String str = "bool:"+ b + " int:" + i + " float:" + f + " double:" + d + " String:" + s;
		System.out.println("----callNativeFunShowText----out runOnGLThread-----"+str);
		appActivity.runOnGLThread(new Runnable(){
			public void run(){
				System.out.println("----callNativeFunShowText----in runOnGLThread-----"+str);
				NativeFunShowText(str);
			}
		});
	}	
}
