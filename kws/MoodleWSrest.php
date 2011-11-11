<?php
/**
 * MoodleWSrest class file
 * 
 * @author    Patrick Pollet :<patrick.pollet@insa-lyon.fr>
 * @copyright (c) P.Pollet 2007 under GPL
 * @package   MoodleWS
 */

define('DEBUG',true);
/**
 * affectRecord class
 */
require_once 'affectRecord.php';
/**
 * userRecord class
 */
require_once 'userRecord.php';
/**
 * contactRecord class
 */
require_once 'contactRecord.php';
/**
 * groupRecord class
 */
require_once 'groupRecord.php';
/**
 * groupingRecord class
 */
require_once 'groupingRecord.php';
/**
 * cohortRecord class
 */
require_once 'cohortRecord.php';
/**
 * sectionRecord class
 */
require_once 'sectionRecord.php';
/**
 * courseRecord class
 */
require_once 'courseRecord.php';
/**
 * gradeRecord class
 */
require_once 'gradeRecord.php';
/**
 * gradeItemRecord class
 */
require_once 'gradeItemRecord.php';
/**
 * enrolRecord class
 */
require_once 'enrolRecord.php';
/**
 * eventRecord class
 */
require_once 'eventRecord.php';
/**
 * changeRecord class
 */
require_once 'changeRecord.php';
/**
 * roleRecord class
 */
require_once 'roleRecord.php';
/**
 * categoryRecord class
 */
require_once 'categoryRecord.php';
/**
 * resourceRecord class
 */
require_once 'resourceRecord.php';
/**
 * activityRecord class
 */
require_once 'activityRecord.php';
/**
 * fileRecord class
 */
require_once 'fileRecord.php';
/**
 * profileitemRecord class
 */
require_once 'profileitemRecord.php';
/**
 * assignmentSubmissionRecord class
 */
require_once 'assignmentSubmissionRecord.php';
/**
 * labelRecord class
 */
require_once 'labelRecord.php';
/**
 * forumRecord class
 */
require_once 'forumRecord.php';
/**
 * assignmentRecord class
 */
require_once 'assignmentRecord.php';
/**
 * databaseRecord class
 */
require_once 'databaseRecord.php';
/**
 * wikiRecord class
 */
require_once 'wikiRecord.php';
/**
 * pageWikiRecord class
 */
require_once 'pageWikiRecord.php';
/**
 * quizRecord class
 */
require_once 'quizRecord.php';
/**
 * forumDiscussionRecord class
 */
require_once 'forumDiscussionRecord.php';
/**
 * forumPostRecord class
 */
require_once 'forumPostRecord.php';
/**
 * messageRecord class
 */
require_once 'messageRecord.php';
/**
 * userDatum class
 */
require_once 'userDatum.php';
/**
 * courseDatum class
 */
require_once 'courseDatum.php';
/**
 * labelDatum class
 */
require_once 'labelDatum.php';
/**
 * groupDatum class
 */
require_once 'groupDatum.php';
/**
 * cohortDatum class
 */
require_once 'cohortDatum.php';
/**
 * groupingDatum class
 */
require_once 'groupingDatum.php';
/**
 * categoryDatum class
 */
require_once 'categoryDatum.php';
/**
 * sectionDatum class
 */
require_once 'sectionDatum.php';
/**
 * forumDatum class
 */
require_once 'forumDatum.php';
/**
 * assignmentDatum class
 */
require_once 'assignmentDatum.php';
/**
 * databaseDatum class
 */
require_once 'databaseDatum.php';
/**
 * wikiDatum class
 */
require_once 'wikiDatum.php';
/**
 * pageWikiDatum class
 */
require_once 'pageWikiDatum.php';
/**
 * forumDiscussionDatum class
 */
require_once 'forumDiscussionDatum.php';
/**
 * forumPostDatum class
 */
require_once 'forumPostDatum.php';
/**
 * loginReturn class
 */
require_once 'loginReturn.php';
/**
 * editUsersInput class
 */
require_once 'editUsersInput.php';
/**
 * editUsersOutput class
 */
require_once 'editUsersOutput.php';
/**
 * getUsersReturn class
 */
require_once 'getUsersReturn.php';
/**
 * editCoursesInput class
 */
require_once 'editCoursesInput.php';
/**
 * editCoursesOutput class
 */
require_once 'editCoursesOutput.php';
/**
 * getCoursesReturn class
 */
require_once 'getCoursesReturn.php';
/**
 * getGradesReturn class
 */
require_once 'getGradesReturn.php';
/**
 * getModuleGradesReturn class
 */
require_once 'getModuleGradesReturn.php';
/**
 * enrolStudentsReturn class
 */
require_once 'enrolStudentsReturn.php';
/**
 * getRolesReturn class
 */
require_once 'getRolesReturn.php';
/**
 * getGroupsReturn class
 */
require_once 'getGroupsReturn.php';
/**
 * getGroupingsReturn class
 */
require_once 'getGroupingsReturn.php';
/**
 * getCohortsReturn class
 */
require_once 'getCohortsReturn.php';
/**
 * getEventsReturn class
 */
require_once 'getEventsReturn.php';
/**
 * getLastChangesReturn class
 */
require_once 'getLastChangesReturn.php';
/**
 * getCategoriesReturn class
 */
require_once 'getCategoriesReturn.php';
/**
 * getResourcesReturn class
 */
require_once 'getResourcesReturn.php';
/**
 * getSectionsReturn class
 */
require_once 'getSectionsReturn.php';
/**
 * getActivitiesReturn class
 */
require_once 'getActivitiesReturn.php';
/**
 * getAssignmentSubmissionsReturn class
 */
require_once 'getAssignmentSubmissionsReturn.php';
/**
 * setUserProfileValuesReturn class
 */
require_once 'setUserProfileValuesReturn.php';
/**
 * editLabelsInput class
 */
require_once 'editLabelsInput.php';
/**
 * editLabelsOutput class
 */
require_once 'editLabelsOutput.php';
/**
 * editGroupsInput class
 */
require_once 'editGroupsInput.php';
/**
 * editGroupsOutput class
 */
require_once 'editGroupsOutput.php';
/**
 * editGroupingsInput class
 */
require_once 'editGroupingsInput.php';
/**
 * editGroupingsOutput class
 */
require_once 'editGroupingsOutput.php';
/**
 * editCohortsInput class
 */
require_once 'editCohortsInput.php';
/**
 * editCohortsOutput class
 */
require_once 'editCohortsOutput.php';
/**
 * editCategoriesInput class
 */
require_once 'editCategoriesInput.php';
/**
 * editCategoriesOutput class
 */
require_once 'editCategoriesOutput.php';
/**
 * editSectionsInput class
 */
require_once 'editSectionsInput.php';
/**
 * editSectionsOutput class
 */
require_once 'editSectionsOutput.php';
/**
 * editForumsInput class
 */
require_once 'editForumsInput.php';
/**
 * editForumsOutput class
 */
require_once 'editForumsOutput.php';
/**
 * editAssignmentsInput class
 */
require_once 'editAssignmentsInput.php';
/**
 * editAssignmentsOutput class
 */
require_once 'editAssignmentsOutput.php';
/**
 * editDatabasesInput class
 */
require_once 'editDatabasesInput.php';
/**
 * editDatabasesOutput class
 */
require_once 'editDatabasesOutput.php';
/**
 * editWikisInput class
 */
require_once 'editWikisInput.php';
/**
 * editWikisOutput class
 */
require_once 'editWikisOutput.php';
/**
 * editPagesWikiInput class
 */
require_once 'editPagesWikiInput.php';
/**
 * editPagesWikiOutput class
 */
require_once 'editPagesWikiOutput.php';
/**
 * getAllForumsReturn class
 */
require_once 'getAllForumsReturn.php';
/**
 * getAllLabelsReturn class
 */
require_once 'getAllLabelsReturn.php';
/**
 * getAllWikisReturn class
 */
require_once 'getAllWikisReturn.php';
/**
 * getAllPagesWikiReturn class
 */
require_once 'getAllPagesWikiReturn.php';
/**
 * getAllAssignmentsReturn class
 */
require_once 'getAllAssignmentsReturn.php';
/**
 * getAllDatabasesReturn class
 */
require_once 'getAllDatabasesReturn.php';
/**
 * getAllQuizzesReturn class
 */
require_once 'getAllQuizzesReturn.php';
/**
 * getAllGroupingsReturn class
 */
require_once 'getAllGroupingsReturn.php';
/**
 * getForumDiscussionsReturn class
 */
require_once 'getForumDiscussionsReturn.php';
/**
 * getForumPostsReturn class
 */
require_once 'getForumPostsReturn.php';
/**
 * getMessagesReturn class
 */
require_once 'getMessagesReturn.php';
/**
 * getMessageContactsReturn class
 */
require_once 'getMessageContactsReturn.php';

/**
 * MoodleWSrest class
		* the two attributes are made public for debugging purpose
		* i.e. accessing $client->client->__getLast* methods
 * 
 *  
 * 
 * @author    Patrick Pollet :<patrick.pollet@insa-lyon.fr>
 * @copyright (c) P.Pollet 2007 under GPL
 * @package   MoodleWS
 */
class MoodleWSrest {

	    private $serviceurl='';
		private $formatout='php';
	    private $verbose=false;
	    private $postdata='';
	    public $requestResponse='';


		/**
		 * Constructor method
		 * @param string $wsdl URL of the WSDL
		 * @param string $uri
		 * @param string[] $options  Soap Client options array (see PHP5 documentation)
		 * @return MoodleWSrest
		 */
  public function MoodleWSrest($serviceurl = "http://localhost/moodle2/wspp/service_pp.php", $options = array()) {
     $this->serviceurl=$serviceurl;
      $this->verbose=! empty($options['trace']);
 		if (!empty($options['formatout']))
     			$this->setFormatout($options['formatout']);
  }


      private function castTo($className,$res){
        	if ($this->formatout==='php') return $res;  //already done
            if (class_exists($className)) {
                $aux= new $className();
                foreach ($res as $key=>$value)
                    $aux->$key=$value;
                return $aux;
             } else
                return $res;
        }



	/**
	 * @param string 
	 */
	function __call ($methodname, $params) {
		$params['wsformatout']=$this->formatout;
		$params['wsfunction']=$methodname;
          // forcing the separator to '&' is capital with some php version that use otherwise &amp;
        // in 'apache mode' but not in 'cli mode' and break parameter parsing on the server side ...
		$this->postdata = http_build_query($params,'','&');

		//print_r($this);
		$ch = curl_init();
		curl_setopt($ch, CURLOPT_URL, $this->serviceurl);
		curl_setopt($ch, CURLOPT_HEADER, false);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
		curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'POST');
		curl_setopt($ch, CURLOPT_POST, true);

		curl_setopt($ch, CURLOPT_POSTFIELDS, $this->postdata);
		if ($this->verbose)
			curl_setopt($ch, CURLOPT_VERBOSE, true);
		$this->requestResponse = curl_exec($ch);
		//print_r("retour curl".$this->requestResponse);
		curl_close($ch);
		if ($methodname==='login') return $this->deserialize($this->requestResponse,'php');
		else return $this->deserialize($this->requestResponse);

	}



	function deserialize ($data,$formatout='') {
		$formatout=$formatout?$formatout:$this->formatout;
		switch ($formatout) {
			case 'xml':break;
			case 'json':break;
			case 'php':$data=unserialize($data); break;
			case 'dump':break;
		}
		return $data;
	}

	function getFormatout() {
		return $this->formatout;
	}

	function setFormatout($formatout='php') {
		if (empty($formatout)) $formatout='php';
		$this->formatout=$formatout;
	}

	function getPostdata() {
		return $this->postdata;
	}

	function getRequestResponse() {
		return $this->requestResponse;
	}


  /**
   * MoodleWS Client Login 
   *
   * @param string $username
   * @param string $password
   * @return loginReturn
   */
  public function login($username, $password) {
    $res= $this->__call('login', array(
            'username'=>$username,
            'password'=>$password
      ));
  return $this->castTo ('loginReturn',$res);
  }

  /**
   * MoodleWS: Client Logout 
   *
   * @param int $client
   * @param string $sesskey
   * @return boolean
   */
  public function logout($client, $sesskey) {
    $res= $this->__call('logout', array(
            'client'=>$client,
            'sesskey'=>$sesskey
      ));
   return $res;
  }

  /**
   * MoodleWS: Edit Users Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editUsersInput $users
   * @return editUsersOutput
   */
  public function edit_users($client, $sesskey, editUsersInput $users) {
    $res= $this->__call('edit_users', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'users'=>$users
      ));
  return $this->castTo ('editUsersOutput',$res);
  }

  /**
   * MoodleWS: Get Users Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string[] $userids
   * @param string $idfield
   * @return getUsersReturn
   */
  public function get_users($client, $sesskey, $userids, $idfield) {
    $res= $this->__call('get_users', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userids'=>$userids,
            'idfield'=>$idfield
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: Edit Courses Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editCoursesInput $courses
   * @return editCoursesOutput
   */
  public function edit_courses($client, $sesskey, editCoursesInput $courses) {
    $res= $this->__call('edit_courses', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courses'=>$courses
      ));
  return $this->castTo ('editCoursesOutput',$res);
  }

  /**
   * MoodleWS: Get Courses Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string[] $courseids
   * @param string $idfield
   * @return getCoursesReturn
   */
  public function get_courses($client, $sesskey, $courseids, $idfield) {
    $res= $this->__call('get_courses', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseids'=>$courseids,
            'idfield'=>$idfield
      ));
  return $this->castTo ('getCoursesReturn',$res);
  }

  /**
   * MoodleWS: Get Courses Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @return getCoursesReturn
   */
  public function get_courses_search($client, $sesskey, $value) {
    $res= $this->__call('get_courses_search', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value
      ));
  return $this->castTo ('getCoursesReturn',$res);
  }

  /**
   * MoodleWS: Get resources in courses 
   *
   * @param int $client
   * @param string $sesskey
   * @param string[] $courseids
   * @param string $idfield
   * @return getResourcesReturn
   */
  public function get_resources($client, $sesskey, $courseids, $idfield) {
    $res= $this->__call('get_resources', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseids'=>$courseids,
            'idfield'=>$idfield
      ));
  return $this->castTo ('getResourcesReturn',$res);
  }

  /**
   * MoodleWS: get current version 
   *
   * @param int $client
   * @param string $sesskey
   * @return string
   */
  public function get_version($client, $sesskey) {
    $res= $this->__call('get_version', array(
            'client'=>$client,
            'sesskey'=>$sesskey
      ));
   return $res;
  }

  /**
   * MoodleWS: Get Course sections 
   *
   * @param int $client
   * @param string $sesskey
   * @param string[] $courseids
   * @param string $idfield
   * @return getSectionsReturn
   */
  public function get_sections($client, $sesskey, $courseids, $idfield) {
    $res= $this->__call('get_sections', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseids'=>$courseids,
            'idfield'=>$idfield
      ));
  return $this->castTo ('getSectionsReturn',$res);
  }

  /**
   * MoodleWS: Get resources in courses 
   *
   * @param int $client
   * @param string $sesskey
   * @param string[] $courseids
   * @param string $idfield
   * @param string $type
   * @return getResourcesReturn
   */
  public function get_instances_bytype($client, $sesskey, $courseids, $idfield, $type) {
    $res= $this->__call('get_instances_bytype', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseids'=>$courseids,
            'idfield'=>$idfield,
            'type'=>$type
      ));
  return $this->castTo ('getResourcesReturn',$res);
  }

  /**
   * MoodleWS: Get User Grades in some courses 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $userid
   * @param string $userfield
   * @param string[] $courseids
   * @param string $courseidfield
   * @return getGradesReturn
   */
  public function get_grades($client, $sesskey, $userid, $userfield, $courseids, $courseidfield) {
    $res= $this->__call('get_grades', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'userfield'=>$userfield,
            'courseids'=>$courseids,
            'courseidfield'=>$courseidfield
      ));
  return $this->castTo ('getGradesReturn',$res);
  }

  /**
   * MoodleWS: Get User Grades in all courses 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @param string $id
   * @return getGradesReturn
   */
  public function get_user_grades($client, $sesskey, $value, $id) {
    $res= $this->__call('get_user_grades', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value,
            'id'=>$id
      ));
  return $this->castTo ('getGradesReturn',$res);
  }

  /**
   * MoodleWS: Get all Users Grades in one course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @param string $id
   * @return getGradesReturn
   */
  public function get_course_grades($client, $sesskey, $value, $id) {
    $res= $this->__call('get_course_grades', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value,
            'id'=>$id
      ));
  return $this->castTo ('getGradesReturn',$res);
  }

  /**
   * MoodleWS: Enrol students in a course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $courseid
   * @param string $courseidfield
   * @param string[] $userids
   * @param string $useridfield
   * @return enrolStudentsReturn
   */
  public function enrol_students($client, $sesskey, $courseid, $courseidfield, $userids, $useridfield) {
    $res= $this->__call('enrol_students', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'courseidfield'=>$courseidfield,
            'userids'=>$userids,
            'useridfield'=>$useridfield
      ));
  return $this->castTo ('enrolStudentsReturn',$res);
  }

  /**
   * MoodleWS: UnEnrol students in a course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $courseid
   * @param string $courseidfield
   * @param string[] $userids
   * @param string $useridfield
   * @return enrolStudentsReturn
   */
  public function unenrol_students($client, $sesskey, $courseid, $courseidfield, $userids, $useridfield) {
    $res= $this->__call('unenrol_students', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'courseidfield'=>$courseidfield,
            'userids'=>$userids,
            'useridfield'=>$useridfield
      ));
  return $this->castTo ('enrolStudentsReturn',$res);
  }

  /**
   * MoodleWS: Get last changes to a Moodle s
				course 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $courseid
   * @param string $idfield
   * @param int $limit
   * @return getLastChangesReturn
   */
  public function get_last_changes($client, $sesskey, $courseid, $idfield, $limit) {
    $res= $this->__call('get_last_changes', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'idfield'=>$idfield,
            'limit'=>$limit
      ));
  return $this->castTo ('getLastChangesReturn',$res);
  }

  /**
   * MoodleWS: Get Moodle s events 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $eventtype
   * @param string $ownerid
   * @param string $owneridfield
   * @param int $datetimefrom
   * @return getEventsReturn
   */
  public function get_events($client, $sesskey, $eventtype, $ownerid, $owneridfield, $datetimefrom) {
    $res= $this->__call('get_events', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'eventtype'=>$eventtype,
            'ownerid'=>$ownerid,
            'owneridfield'=>$owneridfield,
            'datetimefrom'=>$datetimefrom
      ));
  return $this->castTo ('getEventsReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $courseid
   * @param string $idfield
   * @return getCoursesReturn
   */
  public function get_course($client, $sesskey, $courseid, $idfield) {
    $res= $this->__call('get_course', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'idfield'=>$idfield
      ));
  return $this->castTo ('getCoursesReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $info
   * @return getCoursesReturn
   */
  public function get_course_byid($client, $sesskey, $info) {
    $res= $this->__call('get_course_byid', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'info'=>$info
      ));
  return $this->castTo ('getCoursesReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $info
   * @return getCoursesReturn
   */
  public function get_course_byidnumber($client, $sesskey, $info) {
    $res= $this->__call('get_course_byidnumber', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'info'=>$info
      ));
  return $this->castTo ('getCoursesReturn',$res);
  }

  /**
   * MoodleWS: Get one User Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $userid
   * @param string $idfield
   * @return getUsersReturn
   */
  public function get_user($client, $sesskey, $userid, $idfield) {
    $res= $this->__call('get_user', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'idfield'=>$idfield
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: Get All roles defined in Moodle 
   *
   * @param int $client
   * @param string $sesskey
   * @return getRolesReturn
   */
  public function get_roles($client, $sesskey) {
    $res= $this->__call('get_roles', array(
            'client'=>$client,
            'sesskey'=>$sesskey
      ));
  return $this->castTo ('getRolesReturn',$res);
  }

  /**
   * MoodleWS: Get one role defined in Moodle 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @return getRolesReturn
   */
  public function get_role_byid($client, $sesskey, $value) {
    $res= $this->__call('get_role_byid', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value
      ));
  return $this->castTo ('getRolesReturn',$res);
  }

  /**
   * MoodleWS: Get one role defined in Moodle 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @return getRolesReturn
   */
  public function get_role_byname($client, $sesskey, $value) {
    $res= $this->__call('get_role_byname', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value
      ));
  return $this->castTo ('getRolesReturn',$res);
  }

  /**
   * MoodleWS: Get Moodle course categories 
   *
   * @param int $client
   * @param string $sesskey
   * @return getCategoriesReturn
   */
  public function get_categories($client, $sesskey) {
    $res= $this->__call('get_categories', array(
            'client'=>$client,
            'sesskey'=>$sesskey
      ));
  return $this->castTo ('getCategoriesReturn',$res);
  }

  /**
   * MoodleWS: Get one category defined in Moodle 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @return getCategoriesReturn
   */
  public function get_category_byid($client, $sesskey, $value) {
    $res= $this->__call('get_category_byid', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value
      ));
  return $this->castTo ('getCategoriesReturn',$res);
  }

  /**
   * MoodleWS: Get one category defined in Moodle 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @return getCategoriesReturn
   */
  public function get_category_byname($client, $sesskey, $value) {
    $res= $this->__call('get_category_byname', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value
      ));
  return $this->castTo ('getCategoriesReturn',$res);
  }

  /**
   * MoodleWS: Get Courses user identified by id
				is 
   * member of 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $uid
   * @param string $sort
   * @return getCoursesReturn
   */
  public function get_my_courses($client, $sesskey, $uid, $sort) {
    $res= $this->__call('get_my_courses', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'uid'=>$uid,
            'sort'=>$sort
      ));
  return $this->castTo ('getCoursesReturn',$res);
  }

  /**
   * MoodleWS: Get Courses current user identified
				by 
   * username is member of 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $uinfo
   * @param string $sort
   * @return getCoursesReturn
   */
  public function get_my_courses_byusername($client, $sesskey, $uinfo, $sort) {
    $res= $this->__call('get_my_courses_byusername', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'uinfo'=>$uinfo,
            'sort'=>$sort
      ));
  return $this->castTo ('getCoursesReturn',$res);
  }

  /**
   * MoodleWS: Get Courses current user identified
				by 
   * idnumber is member of 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $uinfo
   * @param string $sort
   * @return getCoursesReturn
   */
  public function get_my_courses_byidnumber($client, $sesskey, $uinfo, $sort) {
    $res= $this->__call('get_my_courses_byidnumber', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'uinfo'=>$uinfo,
            'sort'=>$sort
      ));
  return $this->castTo ('getCoursesReturn',$res);
  }

  /**
   * MoodleWS: Get user info from Moodle user
				login 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $userinfo
   * @return getUsersReturn
   */
  public function get_user_byusername($client, $sesskey, $userinfo) {
    $res= $this->__call('get_user_byusername', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userinfo'=>$userinfo
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: Get user info from Moodle user id
				number 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $userinfo
   * @return getUsersReturn
   */
  public function get_user_byidnumber($client, $sesskey, $userinfo) {
    $res= $this->__call('get_user_byidnumber', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userinfo'=>$userinfo
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: Get user info from Moodle user id 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $userinfo
   * @return getUsersReturn
   */
  public function get_user_byid($client, $sesskey, $userinfo) {
    $res= $this->__call('get_user_byid', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userinfo'=>$userinfo
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: Get users having a role in a course 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $idcourse
   * @param string $idfield
   * @param int $idrole
   * @return getUsersReturn
   */
  public function get_users_bycourse($client, $sesskey, $idcourse, $idfield, $idrole) {
    $res= $this->__call('get_users_bycourse', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'idcourse'=>$idcourse,
            'idfield'=>$idfield,
            'idrole'=>$idrole
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: count users having a role in a
				course 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $idcourse
   * @param string $idfield
   * @param int $idrole
   * @return int
   */
  public function count_users_bycourse($client, $sesskey, $idcourse, $idfield, $idrole) {
    $res= $this->__call('count_users_bycourse', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'idcourse'=>$idcourse,
            'idfield'=>$idfield,
            'idrole'=>$idrole
      ));
   return $res;
  }

  /**
   * MoodleWS: Get Courses belonging to category 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $categoryid
   * @return getCoursesReturn
   */
  public function get_courses_bycategory($client, $sesskey, $categoryid) {
    $res= $this->__call('get_courses_bycategory', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'categoryid'=>$categoryid
      ));
  return $this->castTo ('getCoursesReturn',$res);
  }

  /**
   * MoodleWS: Get Course groups 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $courseid
   * @param string $idfield
   * @return getGroupsReturn
   */
  public function get_groups_bycourse($client, $sesskey, $courseid, $idfield) {
    $res= $this->__call('get_groups_bycourse', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'idfield'=>$idfield
      ));
  return $this->castTo ('getGroupsReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $info
   * @param int $courseid
   * @return getGroupsReturn
   */
  public function get_group_byid($client, $sesskey, $info, $courseid) {
    $res= $this->__call('get_group_byid', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'info'=>$info,
            'courseid'=>$courseid
      ));
  return $this->castTo ('getGroupsReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $info
   * @param int $courseid
   * @return getGroupsReturn
   */
  public function get_groups_byname($client, $sesskey, $info, $courseid) {
    $res= $this->__call('get_groups_byname', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'info'=>$info,
            'courseid'=>$courseid
      ));
  return $this->castTo ('getGroupsReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $info
   * @param int $courseid
   * @return getGroupingsReturn
   */
  public function get_grouping_byid($client, $sesskey, $info, $courseid) {
    $res= $this->__call('get_grouping_byid', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'info'=>$info,
            'courseid'=>$courseid
      ));
  return $this->castTo ('getGroupingsReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $info
   * @param int $courseid
   * @return getGroupingsReturn
   */
  public function get_groupings_byname($client, $sesskey, $info, $courseid) {
    $res= $this->__call('get_groupings_byname', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'info'=>$info,
            'courseid'=>$courseid
      ));
  return $this->castTo ('getGroupingsReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $info
   * @param int $courseid
   * @return getCohortsReturn
   */
  public function get_cohort_byid($client, $sesskey, $info, $courseid) {
    $res= $this->__call('get_cohort_byid', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'info'=>$info,
            'courseid'=>$courseid
      ));
  return $this->castTo ('getCohortsReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $info
   * @param int $courseid
   * @return getCohortsReturn
   */
  public function get_cohort_byidnumber($client, $sesskey, $info, $courseid) {
    $res= $this->__call('get_cohort_byidnumber', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'info'=>$info,
            'courseid'=>$courseid
      ));
  return $this->castTo ('getCohortsReturn',$res);
  }

  /**
   * MoodleWS: Get Course Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $info
   * @param int $courseid
   * @return getCohortsReturn
   */
  public function get_cohorts_byname($client, $sesskey, $info, $courseid) {
    $res= $this->__call('get_cohorts_byname', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'info'=>$info,
            'courseid'=>$courseid
      ));
  return $this->castTo ('getCohortsReturn',$res);
  }

  /**
   * MoodleWS: Get users members of a group in
				course 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $groupid
   * @return getUsersReturn
   */
  public function get_group_members($client, $sesskey, $groupid) {
    $res= $this->__call('get_group_members', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'groupid'=>$groupid
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: Get users members of a grouping in
				course 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $groupid
   * @return getUsersReturn
   */
  public function get_grouping_members($client, $sesskey, $groupid) {
    $res= $this->__call('get_grouping_members', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'groupid'=>$groupid
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: Get users members of a cohort in
				Moodle 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $groupid
   * @return getUsersReturn
   */
  public function get_cohort_members($client, $sesskey, $groupid) {
    $res= $this->__call('get_cohort_members', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'groupid'=>$groupid
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: get current user Moodle internal id
				(helper) 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @return int
   */
  public function get_my_id($client, $sesskey) {
    $res= $this->__call('get_my_id', array(
            'client'=>$client,
            'sesskey'=>$sesskey
      ));
   return $res;
  }

  /**
   * MoodleWS: Get user group in course 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $uid
   * @param string $idfield
   * @param int $courseid
   * @param string $courseidfield
   * @return getGroupsReturn
   */
  public function get_my_group($client, $sesskey, $uid, $idfield, $courseid, $courseidfield) {
    $res= $this->__call('get_my_group', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'uid'=>$uid,
            'idfield'=>$idfield,
            'courseid'=>$courseid,
            'courseidfield'=>$courseidfield
      ));
  return $this->castTo ('getGroupsReturn',$res);
  }

  /**
   * MoodleWS: Get user groups in all Moodle site 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $uid
   * @param string $idfield
   * @return getGroupsReturn
   */
  public function get_my_groups($client, $sesskey, $uid, $idfield) {
    $res= $this->__call('get_my_groups', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'uid'=>$uid,
            'idfield'=>$idfield
      ));
  return $this->castTo ('getGroupsReturn',$res);
  }

  /**
   * MoodleWS: Get user groups in all Moodle site 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $uid
   * @param string $idfield
   * @return getCohortsReturn
   */
  public function get_my_cohorts($client, $sesskey, $uid, $idfield) {
    $res= $this->__call('get_my_cohorts', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'uid'=>$uid,
            'idfield'=>$idfield
      ));
  return $this->castTo ('getCohortsReturn',$res);
  }

  /**
   * MoodleWS: Get course teachers 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @param string $id
   * @return getUsersReturn
   */
  public function get_teachers($client, $sesskey, $value, $id) {
    $res= $this->__call('get_teachers', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value,
            'id'=>$id
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: Get course students 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @param string $id
   * @return getUsersReturn
   */
  public function get_students($client, $sesskey, $value, $id) {
    $res= $this->__call('get_students', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value,
            'id'=>$id
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: check if user has a given role in a
				given 
   * course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $iduser
   * @param string $iduserfield
   * @param string $idcourse
   * @param string $idcoursefield
   * @param int $idrole
   * @return boolean
   */
  public function has_role_incourse($client, $sesskey, $iduser, $iduserfield, $idcourse, $idcoursefield, $idrole) {
    $res= $this->__call('has_role_incourse', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'iduser'=>$iduser,
            'iduserfield'=>$iduserfield,
            'idcourse'=>$idcourse,
            'idcoursefield'=>$idcoursefield,
            'idrole'=>$idrole
      ));
   return $res;
  }

  /**
   * MoodleWS: returns user s primary role in a
				given 
   * course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $iduser
   * @param string $iduserfield
   * @param string $idcourse
   * @param string $idcoursefield
   * @return int
   */
  public function get_primaryrole_incourse($client, $sesskey, $iduser, $iduserfield, $idcourse, $idcoursefield) {
    $res= $this->__call('get_primaryrole_incourse', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'iduser'=>$iduser,
            'iduserfield'=>$iduserfield,
            'idcourse'=>$idcourse,
            'idcoursefield'=>$idcoursefield
      ));
   return $res;
  }

  /**
   * MoodleWS: Get user most recent activities in
				a 
   * Moodle course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $iduser
   * @param string $iduserfield
   * @param string $idcourse
   * @param string $idcoursefield
   * @param int $idlimit
   * @return getActivitiesReturn
   */
  public function get_activities($client, $sesskey, $iduser, $iduserfield, $idcourse, $idcoursefield, $idlimit) {
    $res= $this->__call('get_activities', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'iduser'=>$iduser,
            'iduserfield'=>$iduserfield,
            'idcourse'=>$idcourse,
            'idcoursefield'=>$idcoursefield,
            'idlimit'=>$idlimit
      ));
  return $this->castTo ('getActivitiesReturn',$res);
  }

  /**
   * MoodleWS: count user most recent activities
				in 
   * a Moodle course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value1
   * @param string $id1
   * @param string $value2
   * @param string $id2
   * @return int
   */
  public function count_activities($client, $sesskey, $value1, $id1, $value2, $id2) {
    $res= $this->__call('count_activities', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value1'=>$value1,
            'id1'=>$id1,
            'value2'=>$value2,
            'id2'=>$id2
      ));
   return $res;
  }

  /**
   * MoodleWS: get files submitted
				in a Moodle 
   * assignment 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $assignmentid
   * @param string[] $userids
   * @param string $useridfield
   * @param int $timemodified
   * @return getAssignmentSubmissionsReturn
   */
  public function get_assignment_submissions($client, $sesskey, $assignmentid, $userids, $useridfield, $timemodified) {
    $res= $this->__call('get_assignment_submissions', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'assignmentid'=>$assignmentid,
            'userids'=>$userids,
            'useridfield'=>$useridfield,
            'timemodified'=>$timemodified
      ));
  return $this->castTo ('getAssignmentSubmissionsReturn',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param userDatum $user
   * @return editUsersOutput
   */
  public function add_user($client, $sesskey, userDatum $user) {
    $res= $this->__call('add_user', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'user'=>$user
      ));
  return $this->castTo ('editUsersOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param courseDatum $course
   * @return editCoursesOutput
   */
  public function add_course($client, $sesskey, courseDatum $course) {
    $res= $this->__call('add_course', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'course'=>$course
      ));
  return $this->castTo ('editCoursesOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param groupDatum $group
   * @return editGroupsOutput
   */
  public function add_group($client, $sesskey, groupDatum $group) {
    $res= $this->__call('add_group', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'group'=>$group
      ));
  return $this->castTo ('editGroupsOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param groupingDatum $grouping
   * @return editGroupingsOutput
   */
  public function add_grouping($client, $sesskey, groupingDatum $grouping) {
    $res= $this->__call('add_grouping', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'grouping'=>$grouping
      ));
  return $this->castTo ('editGroupingsOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param cohortDatum $cohort
   * @return editCohortsOutput
   */
  public function add_cohort($client, $sesskey, cohortDatum $cohort) {
    $res= $this->__call('add_cohort', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'cohort'=>$cohort
      ));
  return $this->castTo ('editCohortsOutput',$res);
  }

  /**
   * MoodleWS: add a course section 
   *
   * @param int $client
   * @param string $sesskey
   * @param sectionDatum $section
   * @return editSectionsOutput
   */
  public function add_section($client, $sesskey, sectionDatum $section) {
    $res= $this->__call('add_section', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'section'=>$section
      ));
  return $this->castTo ('editSectionsOutput',$res);
  }

  /**
   * MoodleWS: add a label 
   *
   * @param int $client
   * @param string $sesskey
   * @param labelDatum $label
   * @return editLabelsOutput
   */
  public function add_label($client, $sesskey, labelDatum $label) {
    $res= $this->__call('add_label', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'label'=>$label
      ));
  return $this->castTo ('editLabelsOutput',$res);
  }

  /**
   * MoodleWS: add a forum 
   *
   * @param int $client
   * @param string $sesskey
   * @param forumDatum $forum
   * @return editForumsOutput
   */
  public function add_forum($client, $sesskey, forumDatum $forum) {
    $res= $this->__call('add_forum', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'forum'=>$forum
      ));
  return $this->castTo ('editForumsOutput',$res);
  }

  /**
   * MoodleWS: add a course category 
   *
   * @param int $client
   * @param string $sesskey
   * @param databaseDatum $database
   * @return editDatabasesOutput
   */
  public function add_database($client, $sesskey, databaseDatum $database) {
    $res= $this->__call('add_database', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'database'=>$database
      ));
  return $this->castTo ('editDatabasesOutput',$res);
  }

  /**
   * MoodleWS: add an assignment 
   *
   * @param int $client
   * @param string $sesskey
   * @param assignmentDatum $assignment
   * @return editAssignmentsOutput
   */
  public function add_assignment($client, $sesskey, assignmentDatum $assignment) {
    $res= $this->__call('add_assignment', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'assignment'=>$assignment
      ));
  return $this->castTo ('editAssignmentsOutput',$res);
  }

  /**
   * MoodleWS: add a course category 
   *
   * @param int $client
   * @param string $sesskey
   * @param wikiDatum $wiki
   * @return editWikisOutput
   */
  public function add_wiki($client, $sesskey, wikiDatum $wiki) {
    $res= $this->__call('add_wiki', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'wiki'=>$wiki
      ));
  return $this->castTo ('editWikisOutput',$res);
  }

  /**
   * MoodleWS: add a course category 
   *
   * @param int $client
   * @param string $sesskey
   * @param pageWikiDatum $page
   * @return editPagesWikiOutput
   */
  public function add_pagewiki($client, $sesskey, pageWikiDatum $page) {
    $res= $this->__call('add_pagewiki', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'page'=>$page
      ));
  return $this->castTo ('editPagesWikiOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @param string $id
   * @return editUsersOutput
   */
  public function delete_user($client, $sesskey, $value, $id) {
    $res= $this->__call('delete_user', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value,
            'id'=>$id
      ));
  return $this->castTo ('editUsersOutput',$res);
  }

  /**
   * MoodleWS: add a course category 
   *
   * @param int $client
   * @param string $sesskey
   * @param categoryDatum $category
   * @return editCategoriesOutput
   */
  public function add_category($client, $sesskey, categoryDatum $category) {
    $res= $this->__call('add_category', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'category'=>$category
      ));
  return $this->castTo ('editCategoriesOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @param string $id
   * @return editCoursesOutput
   */
  public function delete_course($client, $sesskey, $value, $id) {
    $res= $this->__call('delete_course', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value,
            'id'=>$id
      ));
  return $this->castTo ('editCoursesOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @param string $id
   * @return editGroupsOutput
   */
  public function delete_group($client, $sesskey, $value, $id) {
    $res= $this->__call('delete_group', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value,
            'id'=>$id
      ));
  return $this->castTo ('editGroupsOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @param string $id
   * @return editGroupingsOutput
   */
  public function delete_grouping($client, $sesskey, $value, $id) {
    $res= $this->__call('delete_grouping', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value,
            'id'=>$id
      ));
  return $this->castTo ('editGroupingsOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value
   * @param string $id
   * @return editCohortsOutput
   */
  public function delete_cohort($client, $sesskey, $value, $id) {
    $res= $this->__call('delete_cohort', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value'=>$value,
            'id'=>$id
      ));
  return $this->castTo ('editCohortsOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param userDatum $user
   * @param string $idfield
   * @return editUsersOutput
   */
  public function update_user($client, $sesskey, userDatum $user, $idfield) {
    $res= $this->__call('update_user', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'user'=>$user,
            'idfield'=>$idfield
      ));
  return $this->castTo ('editUsersOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param courseDatum $course
   * @param string $idfield
   * @return editCoursesOutput
   */
  public function update_course($client, $sesskey, courseDatum $course, $idfield) {
    $res= $this->__call('update_course', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'course'=>$course,
            'idfield'=>$idfield
      ));
  return $this->castTo ('editCoursesOutput',$res);
  }

  /**
   * MoodleWS: add a course section 
   *
   * @param int $client
   * @param string $sesskey
   * @param sectionDatum $section
   * @param string $idfield
   * @return editSectionsOutput
   */
  public function update_section($client, $sesskey, sectionDatum $section, $idfield) {
    $res= $this->__call('update_section', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'section'=>$section,
            'idfield'=>$idfield
      ));
  return $this->castTo ('editSectionsOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param groupDatum $group
   * @param string $idfield
   * @return editGroupsOutput
   */
  public function update_group($client, $sesskey, groupDatum $group, $idfield) {
    $res= $this->__call('update_group', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'group'=>$group,
            'idfield'=>$idfield
      ));
  return $this->castTo ('editGroupsOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param groupingDatum $grouping
   * @param string $idfield
   * @return editGroupingsOutput
   */
  public function update_grouping($client, $sesskey, groupingDatum $grouping, $idfield) {
    $res= $this->__call('update_grouping', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'grouping'=>$grouping,
            'idfield'=>$idfield
      ));
  return $this->castTo ('editGroupingsOutput',$res);
  }

  /**
   * MoodleWS: add on course 
   *
   * @param int $client
   * @param string $sesskey
   * @param cohortDatum $cohort
   * @param string $idfield
   * @return editCohortsOutput
   */
  public function update_cohort($client, $sesskey, cohortDatum $cohort, $idfield) {
    $res= $this->__call('update_cohort', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'cohort'=>$cohort,
            'idfield'=>$idfield
      ));
  return $this->castTo ('editCohortsOutput',$res);
  }

  /**
   * MoodleWS: Edit Label Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editLabelsInput $labels
   * @return editLabelsOutput
   */
  public function edit_labels($client, $sesskey, editLabelsInput $labels) {
    $res= $this->__call('edit_labels', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'labels'=>$labels
      ));
  return $this->castTo ('editLabelsOutput',$res);
  }

  /**
   * MoodleWS: Edit Groups Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editGroupsInput $groups
   * @return editGroupsOutput
   */
  public function edit_groups($client, $sesskey, editGroupsInput $groups) {
    $res= $this->__call('edit_groups', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'groups'=>$groups
      ));
  return $this->castTo ('editGroupsOutput',$res);
  }

  /**
   * MoodleWS: Edit Assignment Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editAssignmentsInput $assignments
   * @return editAssignmentsOutput
   */
  public function edit_assignments($client, $sesskey, editAssignmentsInput $assignments) {
    $res= $this->__call('edit_assignments', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'assignments'=>$assignments
      ));
  return $this->castTo ('editAssignmentsOutput',$res);
  }

  /**
   * MoodleWS: Edit databases Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editDatabasesInput $databases
   * @return editDatabasesOutput
   */
  public function edit_databases($client, $sesskey, editDatabasesInput $databases) {
    $res= $this->__call('edit_databases', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'databases'=>$databases
      ));
  return $this->castTo ('editDatabasesOutput',$res);
  }

  /**
   * MoodleWS: Edit Categories Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editCategoriesInput $categories
   * @return editCategoriesOutput
   */
  public function edit_categories($client, $sesskey, editCategoriesInput $categories) {
    $res= $this->__call('edit_categories', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'categories'=>$categories
      ));
  return $this->castTo ('editCategoriesOutput',$res);
  }

  /**
   * MoodleWS: Edit section Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editSectionsInput $sections
   * @return editSectionsOutput
   */
  public function edit_sections($client, $sesskey, editSectionsInput $sections) {
    $res= $this->__call('edit_sections', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'sections'=>$sections
      ));
  return $this->castTo ('editSectionsOutput',$res);
  }

  /**
   * MoodleWS: Edit Forum Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editForumsInput $forums
   * @return editForumsOutput
   */
  public function edit_forums($client, $sesskey, editForumsInput $forums) {
    $res= $this->__call('edit_forums', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'forums'=>$forums
      ));
  return $this->castTo ('editForumsOutput',$res);
  }

  /**
   * MoodleWS: Edit Wikis Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editWikisInput $wikis
   * @return editWikisOutput
   */
  public function edit_wikis($client, $sesskey, editWikisInput $wikis) {
    $res= $this->__call('edit_wikis', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'wikis'=>$wikis
      ));
  return $this->castTo ('editWikisOutput',$res);
  }

  /**
   * MoodleWS: Edit Page of Wiki Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editPagesWikiInput $pagesWiki
   * @return editPagesWikiOutput
   */
  public function edit_pagesWiki($client, $sesskey, editPagesWikiInput $pagesWiki) {
    $res= $this->__call('edit_pagesWiki', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'pagesWiki'=>$pagesWiki
      ));
  return $this->castTo ('editPagesWikiOutput',$res);
  }

  /**
   * MoodleWS: Affect Course To Category 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $courseid
   * @param int $categoryid
   * @return affectRecord
   */
  public function affect_course_to_category($client, $sesskey, $courseid, $categoryid) {
    $res= $this->__call('affect_course_to_category', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'categoryid'=>$categoryid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect Label to Section 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $labelid
   * @param int $sectionid
   * @return affectRecord
   */
  public function affect_label_to_section($client, $sesskey, $labelid, $sectionid) {
    $res= $this->__call('affect_label_to_section', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'labelid'=>$labelid,
            'sectionid'=>$sectionid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect Forum to Section 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $forumid
   * @param int $sectionid
   * @param int $groupmode
   * @return affectRecord
   */
  public function affect_forum_to_section($client, $sesskey, $forumid, $sectionid, $groupmode) {
    $res= $this->__call('affect_forum_to_section', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'forumid'=>$forumid,
            'sectionid'=>$sectionid,
            'groupmode'=>$groupmode
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect Section To Course 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $sectionid
   * @param int $courseid
   * @return affectRecord
   */
  public function affect_section_to_course($client, $sesskey, $sectionid, $courseid) {
    $res= $this->__call('affect_section_to_course', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'sectionid'=>$sectionid,
            'courseid'=>$courseid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect a user to group 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $userid
   * @param int $groupid
   * @return affectRecord
   */
  public function affect_user_to_group($client, $sesskey, $userid, $groupid) {
    $res= $this->__call('affect_user_to_group', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'groupid'=>$groupid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect a user to group 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $userid
   * @param int $groupid
   * @return affectRecord
   */
  public function affect_user_to_cohort($client, $sesskey, $userid, $groupid) {
    $res= $this->__call('affect_user_to_cohort', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'groupid'=>$groupid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect a group to course 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $groupid
   * @param int $coursid
   * @return affectRecord
   */
  public function affect_group_to_course($client, $sesskey, $groupid, $coursid) {
    $res= $this->__call('affect_group_to_course', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'groupid'=>$groupid,
            'coursid'=>$coursid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect a wiki to section 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $wikiid
   * @param int $sectionid
   * @param int $groupmode
   * @param int $visible
   * @return affectRecord
   */
  public function affect_wiki_to_section($client, $sesskey, $wikiid, $sectionid, $groupmode, $visible) {
    $res= $this->__call('affect_wiki_to_section', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'wikiid'=>$wikiid,
            'sectionid'=>$sectionid,
            'groupmode'=>$groupmode,
            'visible'=>$visible
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect a database to section 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $databaseid
   * @param int $sectionid
   * @return affectRecord
   */
  public function affect_database_to_section($client, $sesskey, $databaseid, $sectionid) {
    $res= $this->__call('affect_database_to_section', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'databaseid'=>$databaseid,
            'sectionid'=>$sectionid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect a section to assignment 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $assignmentid
   * @param int $sectionid
   * @param int $groupmode
   * @return affectRecord
   */
  public function affect_assignment_to_section($client, $sesskey, $assignmentid, $sectionid, $groupmode) {
    $res= $this->__call('affect_assignment_to_section', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'assignmentid'=>$assignmentid,
            'sectionid'=>$sectionid,
            'groupmode'=>$groupmode
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect user to the course 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $userid
   * @param int $courseid
   * @param string $rolename
   * @return affectRecord
   */
  public function affect_user_to_course($client, $sesskey, $userid, $courseid, $rolename) {
    $res= $this->__call('affect_user_to_course', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'courseid'=>$courseid,
            'rolename'=>$rolename
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect a page of wiki to a wiki 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $pageid
   * @param int $wikiid
   * @return affectRecord
   */
  public function affect_pageWiki_to_wiki($client, $sesskey, $pageid, $wikiid) {
    $res= $this->__call('affect_pageWiki_to_wiki', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'pageid'=>$pageid,
            'wikiid'=>$wikiid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Remove the role specified of the
				user 
   * in the course 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $userid
   * @param int $courseid
   * @param string $rolename
   * @return affectRecord
   */
  public function remove_user_from_course($client, $sesskey, $userid, $courseid, $rolename) {
    $res= $this->__call('remove_user_from_course', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'courseid'=>$courseid,
            'rolename'=>$rolename
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Get All Groups 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getGroupsReturn
   */
  public function get_all_groups($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_groups', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getGroupsReturn',$res);
  }

  /**
   * MoodleWS: Get All Forums 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getAllForumsReturn
   */
  public function get_all_forums($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_forums', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getAllForumsReturn',$res);
  }

  /**
   * MoodleWS: Get All Labels 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getAllLabelsReturn
   */
  public function get_all_labels($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_labels', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getAllLabelsReturn',$res);
  }

  /**
   * MoodleWS: Get All wikis 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getAllWikisReturn
   */
  public function get_all_wikis($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_wikis', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getAllWikisReturn',$res);
  }

  /**
   * MoodleWS: Get All Pages Wikis 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getAllPagesWikiReturn
   */
  public function get_all_pagesWiki($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_pagesWiki', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getAllPagesWikiReturn',$res);
  }

  /**
   * MoodleWS: Get All Assignments 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getAllAssignmentsReturn
   */
  public function get_all_assignments($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_assignments', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getAllAssignmentsReturn',$res);
  }

  /**
   * MoodleWS: Get All Databases 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getAllDatabasesReturn
   */
  public function get_all_databases($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_databases', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getAllDatabasesReturn',$res);
  }

  /**
   * MoodleWS: Get All quizzes 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getAllQuizzesReturn
   */
  public function get_all_quizzes($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_quizzes', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getAllQuizzesReturn',$res);
  }

  /**
   * MoodleWS: Get All groupings 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getGroupingsReturn
   */
  public function get_all_groupings($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_groupings', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getGroupingsReturn',$res);
  }

  /**
   * MoodleWS: Get All cohorts 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $fieldname
   * @param string $fieldvalue
   * @return getCohortsReturn
   */
  public function get_all_cohorts($client, $sesskey, $fieldname, $fieldvalue) {
    $res= $this->__call('get_all_cohorts', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'fieldname'=>$fieldname,
            'fieldvalue'=>$fieldvalue
      ));
  return $this->castTo ('getCohortsReturn',$res);
  }

  /**
   * MoodleWS: unAffect a user to group 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $userid
   * @param int $groupid
   * @return affectRecord
   */
  public function remove_user_from_group($client, $sesskey, $userid, $groupid) {
    $res= $this->__call('remove_user_from_group', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'groupid'=>$groupid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: unAffect a user to group 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $userid
   * @param int $groupid
   * @return affectRecord
   */
  public function remove_user_from_cohort($client, $sesskey, $userid, $groupid) {
    $res= $this->__call('remove_user_from_cohort', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'groupid'=>$groupid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Edit Groups Information 
   *
   * @param int $client
   * @param string $sesskey
   * @param editGroupingsInput $groupings
   * @return editGroupingsOutput
   */
  public function edit_groupings($client, $sesskey, editGroupingsInput $groupings) {
    $res= $this->__call('edit_groupings', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'groupings'=>$groupings
      ));
  return $this->castTo ('editGroupingsOutput',$res);
  }

  /**
   * MoodleWS: unAffect a group to grouping 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $groupid
   * @param int $groupingid
   * @return affectRecord
   */
  public function remove_group_from_grouping($client, $sesskey, $groupid, $groupingid) {
    $res= $this->__call('remove_group_from_grouping', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'groupid'=>$groupid,
            'groupingid'=>$groupingid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Affect a group to grouping 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $groupid
   * @param int $groupingid
   * @return affectRecord
   */
  public function affect_group_to_grouping($client, $sesskey, $groupid, $groupingid) {
    $res= $this->__call('affect_group_to_grouping', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'groupid'=>$groupid,
            'groupingid'=>$groupingid
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: set one user profile values 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $userid
   * @param string $useridfield
   * @param profileitemRecord[] $values
   * @return setUserProfileValuesReturn
   */
  public function set_user_profile_values($client, $sesskey, $userid, $useridfield, $values) {
    $res= $this->__call('set_user_profile_values', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'useridfield'=>$useridfield,
            'values'=>$values
      ));
  return $this->castTo ('setUserProfileValuesReturn',$res);
  }

  /**
   * MoodleWS: get users having some value in a profile 
   * field 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $profilefieldname
   * @param string $profilefieldvalue
   * @return getUsersReturn
   */
  public function get_users_byprofile($client, $sesskey, $profilefieldname, $profilefieldvalue) {
    $res= $this->__call('get_users_byprofile', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'profilefieldname'=>$profilefieldname,
            'profilefieldvalue'=>$profilefieldvalue
      ));
  return $this->castTo ('getUsersReturn',$res);
  }

  /**
   * MoodleWS: export all data of a quiz 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $quizid
   * @param string $quizformat
   * @return quizRecord
   */
  public function get_quiz($client, $sesskey, $quizid, $quizformat) {
    $res= $this->__call('get_quiz', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'quizid'=>$quizid,
            'quizformat'=>$quizformat
      ));
  return $this->castTo ('quizRecord',$res);
  }

  /**
   * MoodleWS: add a teacher in the course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value1
   * @param string $id1
   * @param string $value2
   * @param string $id2
   * @return affectRecord
   */
  public function add_teacher($client, $sesskey, $value1, $id1, $value2, $id2) {
    $res= $this->__call('add_teacher', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value1'=>$value1,
            'id1'=>$id1,
            'value2'=>$value2,
            'id2'=>$id2
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: remove a teacher in the course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value1
   * @param string $id1
   * @param string $value2
   * @param string $id2
   * @return affectRecord
   */
  public function remove_teacher($client, $sesskey, $value1, $id1, $value2, $id2) {
    $res= $this->__call('remove_teacher', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value1'=>$value1,
            'id1'=>$id1,
            'value2'=>$value2,
            'id2'=>$id2
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: add a non editing teacher in the course 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value1
   * @param string $id1
   * @param string $value2
   * @param string $id2
   * @return affectRecord
   */
  public function add_noneditingteacher($client, $sesskey, $value1, $id1, $value2, $id2) {
    $res= $this->__call('add_noneditingteacher', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value1'=>$value1,
            'id1'=>$id1,
            'value2'=>$value2,
            'id2'=>$id2
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: remove  a non edting teacher in the 
   * course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value1
   * @param string $id1
   * @param string $value2
   * @param string $id2
   * @return affectRecord
   */
  public function remove_noneditingteacher($client, $sesskey, $value1, $id1, $value2, $id2) {
    $res= $this->__call('remove_noneditingteacher', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value1'=>$value1,
            'id1'=>$id1,
            'value2'=>$value2,
            'id2'=>$id2
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: add a student in the course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value1
   * @param string $id1
   * @param string $value2
   * @param string $id2
   * @return affectRecord
   */
  public function add_student($client, $sesskey, $value1, $id1, $value2, $id2) {
    $res= $this->__call('add_student', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value1'=>$value1,
            'id1'=>$id1,
            'value2'=>$value2,
            'id2'=>$id2
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: remove a student in the course 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $value1
   * @param string $id1
   * @param string $value2
   * @param string $id2
   * @return affectRecord
   */
  public function remove_student($client, $sesskey, $value1, $id1, $value2, $id2) {
    $res= $this->__call('remove_student', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'value1'=>$value1,
            'id1'=>$id1,
            'value2'=>$value2,
            'id2'=>$id2
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Enrol students in a cohort 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $courseid
   * @param string $courseidfield
   * @param string[] $userids
   * @param string $useridfield
   * @return enrolStudentsReturn
   */
  public function affect_users_to_cohort($client, $sesskey, $courseid, $courseidfield, $userids, $useridfield) {
    $res= $this->__call('affect_users_to_cohort', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'courseidfield'=>$courseidfield,
            'userids'=>$userids,
            'useridfield'=>$useridfield
      ));
  return $this->castTo ('enrolStudentsReturn',$res);
  }

  /**
   * MoodleWS: Unenrol students in a cohort 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $courseid
   * @param string $courseidfield
   * @param string[] $userids
   * @param string $useridfield
   * @return enrolStudentsReturn
   */
  public function remove_users_from_cohort($client, $sesskey, $courseid, $courseidfield, $userids, $useridfield) {
    $res= $this->__call('remove_users_from_cohort', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'courseidfield'=>$courseidfield,
            'userids'=>$userids,
            'useridfield'=>$useridfield
      ));
  return $this->castTo ('enrolStudentsReturn',$res);
  }

  /**
   * MoodleWS: Enrol students in a cohort 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $courseid
   * @param string $courseidfield
   * @param string[] $userids
   * @param string $useridfield
   * @return enrolStudentsReturn
   */
  public function affect_users_to_group($client, $sesskey, $courseid, $courseidfield, $userids, $useridfield) {
    $res= $this->__call('affect_users_to_group', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'courseidfield'=>$courseidfield,
            'userids'=>$userids,
            'useridfield'=>$useridfield
      ));
  return $this->castTo ('enrolStudentsReturn',$res);
  }

  /**
   * MoodleWS: Unenrol students in a cohort 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $courseid
   * @param string $courseidfield
   * @param string[] $userids
   * @param string $useridfield
   * @return enrolStudentsReturn
   */
  public function remove_users_from_group($client, $sesskey, $courseid, $courseidfield, $userids, $useridfield) {
    $res= $this->__call('remove_users_from_group', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'courseid'=>$courseid,
            'courseidfield'=>$courseidfield,
            'userids'=>$userids,
            'useridfield'=>$useridfield
      ));
  return $this->castTo ('enrolStudentsReturn',$res);
  }

  /**
   * MoodleWS: Get 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $forumid
   * @param int $limit
   * @return getForumDiscussionsReturn
   */
  public function get_forum_discussions($client, $sesskey, $forumid, $limit) {
    $res= $this->__call('get_forum_discussions', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'forumid'=>$forumid,
            'limit'=>$limit
      ));
  return $this->castTo ('getForumDiscussionsReturn',$res);
  }

  /**
   * MoodleWS: Get 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $discussionid
   * @param int $limit
   * @return getForumPostsReturn
   */
  public function get_forum_posts($client, $sesskey, $discussionid, $limit) {
    $res= $this->__call('get_forum_posts', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'discussionid'=>$discussionid,
            'limit'=>$limit
      ));
  return $this->castTo ('getForumPostsReturn',$res);
  }

  /**
   * MoodleWS: Get 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $forumid
   * @param forumDiscussionDatum $discussion
   * @return getForumDiscussionsReturn
   */
  public function forum_add_discussion($client, $sesskey, $forumid, forumDiscussionDatum $discussion) {
    $res= $this->__call('forum_add_discussion', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'forumid'=>$forumid,
            'discussion'=>$discussion
      ));
  return $this->castTo ('getForumDiscussionsReturn',$res);
  }

  /**
   * MoodleWS: Get 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $parentid
   * @param forumPostDatum $post
   * @return getForumPostsReturn
   */
  public function forum_add_reply($client, $sesskey, $parentid, forumPostDatum $post) {
    $res= $this->__call('forum_add_reply', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'parentid'=>$parentid,
            'post'=>$post
      ));
  return $this->castTo ('getForumPostsReturn',$res);
  }

  /**
   * MoodleWS: Get 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $userid
   * @param string $useridfield
   * @return getMessagesReturn
   */
  public function get_messages($client, $sesskey, $userid, $useridfield) {
    $res= $this->__call('get_messages', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'useridfield'=>$useridfield
      ));
  return $this->castTo ('getMessagesReturn',$res);
  }

  /**
   * MoodleWS: Get 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $useridto
   * @param string $useridtofield
   * @param string $useridfrom
   * @param string $useridfromfield
   * @return getMessagesReturn
   */
  public function get_messages_history($client, $sesskey, $useridto, $useridtofield, $useridfrom, $useridfromfield) {
    $res= $this->__call('get_messages_history', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'useridto'=>$useridto,
            'useridtofield'=>$useridtofield,
            'useridfrom'=>$useridfrom,
            'useridfromfield'=>$useridfromfield
      ));
  return $this->castTo ('getMessagesReturn',$res);
  }

  /**
   * MoodleWS: Get 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $userid
   * @param string $useridfield
   * @param string $message
   * @return affectRecord
   */
  public function message_send($client, $sesskey, $userid, $useridfield, $message) {
    $res= $this->__call('message_send', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'useridfield'=>$useridfield,
            'message'=>$message
      ));
  return $this->castTo ('affectRecord',$res);
  }

  /**
   * MoodleWS: Get user's contacts in Moodle messaging 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param string $userid
   * @param string $useridfield
   * @return getMessageContactsReturn
   */
  public function get_message_contacts($client, $sesskey, $userid, $useridfield) {
    $res= $this->__call('get_message_contacts', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'userid'=>$userid,
            'useridfield'=>$useridfield
      ));
  return $this->castTo ('getMessageContactsReturn',$res);
  }

  /**
   * MoodleWS: Get a resource file by it instance id 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $resourceid
   * @return fileRecord
   */
  public function get_resourcefile_byid($client, $sesskey, $resourceid) {
    $res= $this->__call('get_resourcefile_byid', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'resourceid'=>$resourceid
      ));
  return $this->castTo ('fileRecord',$res);
  }

  /**
   * MoodleWS: Get my grade of a quiz identified by 
   * instance id 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $id
   * @return getModuleGradesReturn
   */
  public function get_my_quiz_grade($client, $sesskey, $id) {
    $res= $this->__call('get_my_quiz_grade', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'id'=>$id
      ));
  return $this->castTo ('getModuleGradesReturn',$res);
  }

  /**
   * MoodleWS: Get my grade of an assignmentidentified 
   * by instance id 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $id
   * @return getModuleGradesReturn
   */
  public function get_my_assignment_grade($client, $sesskey, $id) {
    $res= $this->__call('get_my_assignment_grade', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'id'=>$id
      ));
  return $this->castTo ('getModuleGradesReturn',$res);
  }

  /**
   * MoodleWS: Get my grade of an activity/module of 
   * a certain type identified by instance id 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $id
   * @param string $type
   * @return getModuleGradesReturn
   */
  public function get_my_module_grade($client, $sesskey, $id, $type) {
    $res= $this->__call('get_my_module_grade', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'id'=>$id,
            'type'=>$type
      ));
  return $this->castTo ('getModuleGradesReturn',$res);
  }

  /**
   * MoodleWS: Get grade(s) of an activity of a certain 
   * type identified by instance id for a list of userids 
   * 
   *
   * @param int $client
   * @param string $sesskey
   * @param int $id
   * @param string $type
   * @param string[] $userids
   * @param string $useridfield
   * @return getModuleGradesReturn
   */
  public function get_module_grades($client, $sesskey, $id, $type, $userids, $useridfield) {
    $res= $this->__call('get_module_grades', array(
            'client'=>$client,
            'sesskey'=>$sesskey,
            'id'=>$id,
            'type'=>$type,
            'userids'=>$userids,
            'useridfield'=>$useridfield
      ));
  return $this->castTo ('getModuleGradesReturn',$res);
  }

}

?>
